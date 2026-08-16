
__attribute__((visibility("hidden"))) int __acl_high_water_alloc(void **buf, size_t *bufsize, size_t newsize);

__attribute__((visibility("hidden"))) const char *__acl_quote(const char *str, const char *quote_chars);
__attribute__((visibility("hidden"))) char *__acl_unquote(char *str);

__attribute__((visibility("hidden"))) char *__acl_next_line(FILE *file);
















struct __acl_ext;
struct __acl_entry_ext;
struct __acl_permset_ext;

typedef unsigned int acl_type_t;
typedef int acl_tag_t;
typedef unsigned int acl_perm_t;

typedef struct __acl_ext *acl_t;
typedef struct __acl_entry_ext *acl_entry_t;
typedef struct __acl_permset_ext *acl_permset_t;
__attribute__ ((visibility ("default"))) extern acl_t acl_init(int count);
__attribute__ ((visibility ("default"))) extern acl_t acl_dup(acl_t acl);
__attribute__ ((visibility ("default"))) extern int acl_free(void *obj_p);
__attribute__ ((visibility ("default"))) extern int acl_valid(acl_t acl);



__attribute__ ((visibility ("default"))) extern int
acl_copy_entry(acl_entry_t dest_d, acl_entry_t src_d);
__attribute__ ((visibility ("default"))) extern int acl_create_entry(acl_t *acl_p, acl_entry_t *entry_p);
__attribute__ ((visibility ("default"))) extern int acl_delete_entry(acl_t acl, acl_entry_t entry_d);
__attribute__ ((visibility ("default"))) extern int acl_get_entry(acl_t acl, int entry_id, acl_entry_t *entry_p);



__attribute__ ((visibility ("default"))) extern int acl_add_perm(acl_permset_t permset_d, acl_perm_t perm);
__attribute__ ((visibility ("default"))) extern int acl_calc_mask(acl_t *acl_p);
__attribute__ ((visibility ("default"))) extern int acl_clear_perms(acl_permset_t permset_d);
__attribute__ ((visibility ("default"))) extern int acl_delete_perm(acl_permset_t permset_d, acl_perm_t perm);
__attribute__ ((visibility ("default"))) extern int acl_get_permset(acl_entry_t entry_d, acl_permset_t *permset_p);
__attribute__ ((visibility ("default"))) extern int acl_set_permset(acl_entry_t entry_d, acl_permset_t permset_d);



__attribute__ ((visibility ("default"))) extern void * acl_get_qualifier(acl_entry_t entry_d);
__attribute__ ((visibility ("default"))) extern int acl_get_tag_type(acl_entry_t entry_d, acl_tag_t *tag_type_p);
__attribute__ ((visibility ("default"))) extern int acl_set_qualifier(acl_entry_t entry_d, const void *tag_qualifier_p);
__attribute__ ((visibility ("default"))) extern int acl_set_tag_type(acl_entry_t entry_d, acl_tag_t tag_type);



__attribute__ ((visibility ("default"))) extern ssize_t acl_copy_ext(void *buf_p, acl_t acl, ssize_t size);
__attribute__ ((visibility ("default"))) extern acl_t acl_copy_int(const void *buf_p);
__attribute__ ((visibility ("default"))) extern acl_t acl_from_text(const char *buf_p);
__attribute__ ((visibility ("default"))) extern ssize_t acl_size(acl_t acl);
__attribute__ ((visibility ("default"))) extern char *acl_to_text(acl_t acl, ssize_t *len_p);



__attribute__ ((visibility ("default"))) extern int acl_delete_def_file(const char *path_p);
__attribute__ ((visibility ("default"))) extern acl_t acl_get_fd(int fd);
__attribute__ ((visibility ("default"))) extern acl_t acl_get_file(const char *path_p, acl_type_t type);
__attribute__ ((visibility ("default"))) extern int acl_set_fd(int fd, acl_t acl);
__attribute__ ((visibility ("default"))) extern int acl_set_file(const char *path_p, acl_type_t type, acl_t acl);







typedef unsigned int cmd_tag_t;

struct cmd_obj {
 cmd_tag_t c_cmd;
 acl_type_t c_type;
 acl_tag_t c_tag;
 uid_t c_id;
 mode_t c_perm;
 struct cmd_obj *c_next;
};

typedef struct cmd_obj *cmd_t;

struct seq_obj {
 cmd_t s_first;
 cmd_t s_last;
};

typedef struct seq_obj *seq_t;
cmd_t
cmd_init(
 void);
void
cmd_free(
 cmd_t cmd);
seq_t
seq_init(
 void);
int
seq_free(
 seq_t seq);
int
seq_empty(
 seq_t seq);
int
seq_append(
 seq_t seq,
 cmd_t cmd);
int
seq_append_cmd(
 seq_t seq,
 cmd_tag_t cmd,
 acl_type_t type);
int
seq_get_cmd(
 seq_t seq,
 int which,
 cmd_t *cmd);
int
seq_delete_cmd(
 seq_t seq,
 cmd_t cmd);

cmd_t
parse_acl_cmd(
 const char **text_p,
 int seq_cmd,
 int parse_mode);
int
parse_acl_seq(
 seq_t seq,
 const char *text_p,
 int *which,
 int seq_cmd,
 int parse_mode);
int
read_acl_comments(
 FILE *file,
 int *lineno,
 char **path_p,
 uid_t *uid_p,
 gid_t *gid_p,
 mode_t *flags);
int
read_acl_seq(
 FILE *file,
 seq_t seq,
 int seq_cmd,
 int parse_mode,
 int *lineno,
 int *which);
struct do_set_args {
 seq_t seq;
 mode_t mode;
};

extern int do_set(const char *path_p, const struct stat *stat_p, int flags,
    void *arg);
struct stat;

extern int walk_tree(const char *path, int walk_flags, unsigned int num,
       int (*func)(const char *, const struct stat *, int,
     void *), void *arg);
struct option long_options[] = {

 { "set", 1, 0, 's' },
 { "set-file", 1, 0, 'S' },

 { "mask", 0, 0, 'r' },
 { "recursive", 0, 0, 'R' },
 { "logical", 0, 0, 'L' },
 { "physical", 0, 0, 'P' },
 { "restore", 1, 0, 'B' },
 { "test", 0, 0, 't' },

 { "modify", 1, 0, 'm' },
 { "modify-file", 1, 0, 'M' },
 { "remove", 1, 0, 'x' },
 { "remove-file", 1, 0, 'X' },

 { "default", 0, 0, 'd' },
 { "no-mask", 0, 0, 'n' },
 { "remove-all", 0, 0, 'b' },
 { "remove-default", 0, 0, 'k' },
 { "version", 0, 0, 'v' },
 { "help", 0, 0, 'h' },
 { 
  ((void *)0)
      , 0, 0, 0 },
};

const char *progname;
const char *cmd_line_options, *cmd_line_spec;

int walk_flags = 0x10;
int opt_recalculate;
int opt_promote;
int opt_test;




int posixly_correct;

int chown_error;
int promote_warning;


static const char *xquote(const char *str, const char *quote_chars)
{
 const char *q = __acl_quote(str, quote_chars);
 if (q == 
         ((void *)0)
             ) {
  fprintf(
         stderr
               , "%s: %s\n", progname, strerror(
                                                (*__errno_location ())
                                                     ));
  exit(1);
 }
 return q;
}

int
has_any_of_type(
 cmd_t cmd,
 acl_type_t acl_type)
{
 while (cmd) {
  if (cmd->c_type == acl_type)
   return 1;
  cmd = cmd->c_next;
 }
 return 0;
}



int
restore(
 FILE *file,
 const char *filename)
{
 char *path_p;
 struct stat st;
 uid_t uid;
 gid_t gid;
 mode_t mask, flags;
 struct do_set_args args = { };
 int lineno = 0, backup_line;
 int error, status = 0;
 int chmod_required = 0;

 memset(&st, 0, sizeof(st));

 for(;;) {
  backup_line = lineno;
  error = read_acl_comments(file, &lineno, &path_p, &uid, &gid,
       &flags);
  if (error < 0) {
   error = -error;
   goto fail;
  }
  if (error == 0)
   return status;

  if (path_p == 
               ((void *)0)
                   ) {
   if (filename) {
    fprintf(
           stderr
                 , gettext("%s: %s: No filename found " "in line %d, aborting\n")
                                 ,
     progname, xquote(filename, "\n\r"),
     backup_line);
   } else {
    fprintf(
           stderr
                 , gettext("%s: No filename found in " "line %d of standard input, " "aborting\n")

                    ,
     progname, backup_line);
   }
   status = 1;
   goto getout;
  }

  if (!(args.seq = seq_init()))
   goto fail_errno;
  if (seq_append_cmd(args.seq, (5), (0x8000)) ||
      seq_append_cmd(args.seq, (5), (0x4000)))
   goto fail_errno;

  error = read_acl_seq(file, args.seq, (0),
                       (0x0001) |
         (0x0020) |
         (0x0010),
         &lineno, 
                 ((void *)0)
                     );
  if (error != 0) {
   fprintf(
          stderr
                , gettext("%s: %s: %s in line %d\n"),
           progname, xquote(filename, "\n\r"), strerror(
                                                       (*__errno_location ())
                                                            ),
    lineno);
   status = 1;
   goto getout;
  }

  error = stat(path_p, &st);
  if (opt_test && error != 0) {
   fprintf(
          stderr
                , "%s: %s: %s\n", progname,
    xquote(path_p, "\n\r"), strerror(
                                    (*__errno_location ())
                                         ));
   status = 1;
  }

  args.mode = 0;
  error = do_set(path_p, &st, 0, &args);
  if (error != 0) {
   status = 1;
   goto resume;
  }

  if (uid != ((id_t)-1) && uid != st.st_uid)
   st.st_uid = uid;
  else
   st.st_uid = -1;
  if (gid != ((id_t)-1) && gid != st.st_gid)
   st.st_gid = gid;
  else
   st.st_gid = -1;
  if (!opt_test &&
      (st.st_uid != -1 || st.st_gid != -1)) {
   if (chown(path_p, st.st_uid, st.st_gid) != 0) {
    fprintf(
           stderr
                 , gettext("%s: %s: Cannot change " "owner/group: %s\n")
                                   ,
     progname, xquote(path_p, "\n\r"),
     strerror(
             (*__errno_location ())
                  ));
    status = 1;
   }



   if ((st.st_mode & flags) & (
                              04000 
                                      | 
                                        02000
                                               ))
    chmod_required = 1;
  }

  mask = 
        04000 
                | 
                  02000 
                          | 
                            01000
                                   ;
  if (chmod_required || ((st.st_mode & mask) != (flags & mask))) {
   if (!args.mode)
    args.mode = st.st_mode;
   args.mode &= (
                (0400|0200|0100) 
                        | 
                          ((0400|0200|0100) >> 3) 
                                  | 
                                    (((0400|0200|0100) >> 3) >> 3)
                                           );
   if (chmod(path_p, flags | args.mode) != 0) {
    fprintf(
           stderr
                 , gettext("%s: %s: Cannot change " "mode: %s\n")
                            ,
     progname, xquote(path_p, "\n\r"),
     strerror(
             (*__errno_location ())
                  ));
    status = 1;
   }
  }
resume:
  if (path_p) {
   free(path_p);
   path_p = 
           ((void *)0)
               ;
  }
  if (args.seq) {
   seq_free(args.seq);
   args.seq = 
             ((void *)0)
                 ;
  }
 }

getout:
 if (path_p) {
  free(path_p);
  path_p = 
          ((void *)0)
              ;
 }
 if (args.seq) {
  seq_free(args.seq);
  args.seq = 
            ((void *)0)
                ;
 }
 return status;

fail_errno:
 error = 
        (*__errno_location ())
             ;
fail:
 fprintf(
        stderr
              , "%s: %s: %s\n", progname, xquote(filename, "\n\r"),
  strerror(error));
 status = 1;
 goto getout;
}



void help(void)
{
 printf(gettext("%s %s -- set file access control lists\n"),
  progname, "2.3.1");
 printf(gettext("Usage: %s %s\n"),
  progname, cmd_line_spec);
 printf(gettext("  -m, --modify=acl        modify the current ACL(s) of file(s)\n" "  -M, --modify-file=file  read ACL entries to modify from file\n" "  -x, --remove=acl        remove entries from the ACL(s) of file(s)\n" "  -X, --remove-file=file  read ACL entries to remove from file\n" "  -b, --remove-all        remove all extended ACL entries\n" "  -k, --remove-default    remove the default ACL\n")





                                                     );

 if (!posixly_correct) {
  printf(gettext("      --set=acl           set the ACL of file(s), replacing the current ACL\n" "      --set-file=file     read ACL entries to set from file\n" "      --mask              do recalculate the effective rights mask\n")


                                                                       );
 }

   printf(gettext("  -n, --no-mask           don't recalculate the effective rights mask\n" "  -d, --default           operations apply to the default ACL\n")

                                                                  );

 if (!posixly_correct) {
  printf(gettext("  -R, --recursive         recurse into subdirectories\n" "  -L, --logical           logical walk, follow symbolic links\n" "  -P, --physical          physical walk, do not follow symbolic links\n" "      --restore=file      restore ACLs (inverse of `getfacl -R')\n" "      --test              test mode (ACLs are not modified)\n")




                                                                );
 }

 printf(gettext("  -v, --version           print version and exit\n" "  -h, --help              this help text\n")

                                             );
}


int next_file(const char *arg, seq_t seq)
{
 char *line;
 int errors = 0;
 struct do_set_args args;

 args.seq = seq;

 if (strcmp(arg, "-") == 0) {
  while ((line = __acl_next_line(
                                stdin
                                     )))
   errors = walk_tree(line, walk_flags, 0, do_set, &args);
  if (!feof(
           stdin
                )) {
   fprintf(
          stderr
                , gettext("%s: Standard input: %s\n"),
    progname, strerror(
                      (*__errno_location ())
                           ));
   errors = 1;
  }
 } else {
  errors = walk_tree(arg, walk_flags, 0, do_set, &args);
 }
 return errors ? 1 : 0;
}






int main(int argc, char *argv[])
{
 int opt;
 int saw_files = 0;
 int status = 0;
 FILE *file;
 int which;
 int lineno;
 int error;
 seq_t seq;
 int seq_cmd, parse_mode;

 progname = 
           __xpg_basename
                   (argv[0]);





 if (getenv("POSIXLY_CORRECT"))
  posixly_correct = 1;
 if (!posixly_correct) {
  cmd_line_options = "-:bkndvhm:M:x:X:RLP";
  cmd_line_spec = gettext("[-bkndRLP] { -m|-M|-x|-X ... } file ...");
 } else {
  cmd_line_options = "-:bkndvhm:M:x:X:";
  cmd_line_spec = gettext("[-bknd] {-m|-M|-x|-X ... } file ...");
 }


 setlocale(
          0
                  , "");
 setlocale(
          5
                     , "");
 bindtextdomain("acl", "/usr/share/locale");
 textdomain("acl");

 seq = seq_init();
 if (!seq)
  ({status = (1); goto errno_error; });

 while ((opt = getopt_long(argc, argv, cmd_line_options,
                    long_options, 
                                 ((void *)0)
                                     )) != -1) {


  cmd_t seq_remove_default_acl_cmd = 
                                    ((void *)0)
                                        ;
  cmd_t seq_remove_acl_cmd = 
                            ((void *)0)
                                ;

  if (opt != '\1' && saw_files) {
   seq_free(seq);
   seq = seq_init();
   if (!seq)
    ({status = (1); goto errno_error; });
   saw_files = 0;
  }

  switch (opt) {
   case 'b':
    if (seq_append_cmd(seq, (4),
                            (0x8000)) ||
        seq_append_cmd(seq, (5),
                            (0x4000)))
     ({status = (1); goto errno_error; });
    break;

   case 'k':
    if (seq_append_cmd(seq, (5),
                            (0x4000)))
     ({status = (1); goto errno_error; });
    break;

   case 'n':
    opt_recalculate = -1;
    break;

   case 'r':
    opt_recalculate = 1;
    break;

   case 'd':
    opt_promote = 1;
    break;

   case 's':
    if (seq_append_cmd(seq, (5),
                     (0x8000)))
     ({status = (1); goto errno_error; });
    seq_remove_acl_cmd = seq->s_last;
    if (seq_append_cmd(seq, (5),
                            (0x4000)))
     ({status = (1); goto errno_error; });
    seq_remove_default_acl_cmd = seq->s_last;

    seq_cmd = (0);
    parse_mode = (0x0001);
    goto set_modify_delete;

   case 'm':
    seq_cmd = (0);
    parse_mode = (0x0001);
    goto set_modify_delete;

   case 'x':
    seq_cmd = (3);



    if (posixly_correct)
     parse_mode = (0x0001|0x0002);
    else
     parse_mode = (0x0002);

    goto set_modify_delete;

   set_modify_delete:
    if (!posixly_correct)
     parse_mode |= (0x0020);
    if (opt_promote)
     parse_mode |= (0x0040);
    if (parse_acl_seq(seq, optarg, &which,
                      seq_cmd, parse_mode) != 0) {
     if (which < 0 ||
         (size_t) which >= strlen(optarg)) {
      fprintf(
             stderr
                   , gettext("%s: Option " "-%c incomplete\n")

                                 ,
       progname, opt);
     } else {
      fprintf(
             stderr
                   , gettext("%s: Option " "-%c: %s near " "character %d\n")


                        ,
       progname, opt,
       strerror(
               (*__errno_location ())
                    ),
       which+1);
     }
     status = 2;
     goto cleanup;
    }
    break;

   case 'S':
    if (seq_append_cmd(seq, (5),
                     (0x8000)))
     ({status = (1); goto errno_error; });
    seq_remove_acl_cmd = seq->s_last;
    if (seq_append_cmd(seq, (5),
                            (0x4000)))
     ({status = (1); goto errno_error; });
    seq_remove_default_acl_cmd = seq->s_last;

    seq_cmd = (0);
    parse_mode = (0x0001);
    goto set_modify_delete_from_file;

   case 'M':
    seq_cmd = (0);
    parse_mode = (0x0001);
    goto set_modify_delete_from_file;

   case 'X':
    seq_cmd = (3);



    if (posixly_correct)
     parse_mode = (0x0001|0x0002);
    else
     parse_mode = (0x0002);

    goto set_modify_delete_from_file;

   set_modify_delete_from_file:
    if (!posixly_correct)
     parse_mode |= (0x0020);
    if (opt_promote)
     parse_mode |= (0x0040);
    if (strcmp(optarg, "-") == 0) {
     file = 
           stdin
                ;
    } else {
     file = fopen(optarg, "r");
     if (file == 
                ((void *)0)
                    ) {
      fprintf(
             stderr
                   , "%s: %s: %s\n",
       progname,
       xquote(optarg, "\n\r"),
       strerror(
               (*__errno_location ())
                    ));
      status = 2;
      goto cleanup;
     }
    }

    lineno = 0;
    error = read_acl_seq(file, seq, seq_cmd,
                         parse_mode, &lineno, 
                                             ((void *)0)
                                                 );

    if (file != 
               stdin
                    ) {
     fclose(file);
    }

    if (error) {
     if (!
         (*__errno_location ())
              )
      
     (*__errno_location ()) 
           = 
             22
                   ;

     if (file != 
                stdin
                     ) {
      fprintf(
             stderr
                   , gettext("%s: %s in line " "%d of file %s\n")

                                ,
       progname,
       strerror(
               (*__errno_location ())
                    ),
       lineno,
       xquote(optarg, "\n\r"));
     } else {
      fprintf(
             stderr
                   , gettext("%s: %s in line " "%d of standard " "input\n")


                 , progname,
       strerror(
               (*__errno_location ())
                    ),
       lineno);
     }
     status = 2;
     goto cleanup;
    }
    break;


   case '\1':
    if (seq_empty(seq))
     goto synopsis;
    saw_files = 1;

    status = next_file(optarg, seq);
    break;

   case 'B':
    saw_files = 1;

    if (strcmp(optarg, "-") == 0)
     file = 
           stdin
                ;
    else {
     file = fopen(optarg, "r");
     if (file == 
                ((void *)0)
                    ) {
      fprintf(
             stderr
                   , "%s: %s: %s\n",
       progname,
       xquote(optarg, "\n\r"),
       strerror(
               (*__errno_location ())
                    ));
      status = 2;
      goto cleanup;
     }
    }

    status = restore(file,
                   (file == 
                           stdin
                                ) ? 
                                    ((void *)0) 
                                         : optarg);

    if (file != 
               stdin
                    )
     fclose(file);
    if (status != 0)
     goto cleanup;
    break;

   case 'R':
    walk_flags |= 0x01;
    break;

   case 'L':
    walk_flags |= 0x04 | 0x08;
    walk_flags &= ~0x02;
    break;

   case 'P':
    walk_flags |= 0x02;
    walk_flags &= ~(0x04 | 0x08 |
      0x10);
    break;

   case 't':
    opt_test = 1;
    break;

   case 'v':
    printf("%s " "2.3.1" "\n", progname);
    status = 0;
    goto cleanup;

   case 'h':
    help();
    status = 0;
    goto cleanup;

   case ':':
   case '?':
   default:
    goto synopsis;
  }
  if (seq_remove_acl_cmd) {



   if (!has_any_of_type(seq_remove_acl_cmd->c_next,
                (0x8000)))
    seq_delete_cmd(seq, seq_remove_acl_cmd);
  }
  if (seq_remove_default_acl_cmd) {



   if (!has_any_of_type(seq_remove_default_acl_cmd->c_next,
                (0x4000)))
    seq_delete_cmd(seq, seq_remove_default_acl_cmd);
  }
 }
 while (optind < argc) {
  if(!seq)
   goto synopsis;
  if (seq_empty(seq))
   goto synopsis;
  saw_files = 1;

  status = next_file(argv[optind++], seq);
 }
 if (!saw_files)
  goto synopsis;

 goto cleanup;

synopsis:
 fprintf(
        stderr
              , gettext("Usage: %s %s\n"),
  progname, cmd_line_spec);
 fprintf(
        stderr
              , gettext("Try `%s --help' for more information.\n"),
  progname);
 status = 2;
 goto cleanup;

errno_error:
 fprintf(
        stderr
              , "%s: %s\n", progname, strerror(
                                               (*__errno_location ())
                                                    ));
 goto cleanup;

cleanup:
 if (seq)
  seq_free(seq);
 return status;
}
