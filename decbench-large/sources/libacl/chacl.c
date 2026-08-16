

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
__attribute__ ((visibility ("default"))) extern char *acl_to_any_text(acl_t acl, const char *prefix,
        char separator, int options);
__attribute__ ((visibility ("default"))) extern int acl_cmp(acl_t acl1, acl_t acl2);
__attribute__ ((visibility ("default"))) extern int acl_check(acl_t acl, int *last);
__attribute__ ((visibility ("default"))) extern acl_t acl_from_mode(mode_t mode);
__attribute__ ((visibility ("default"))) extern int acl_equiv_mode(acl_t acl, mode_t *mode_p);
__attribute__ ((visibility ("default"))) extern int acl_extended_file(const char *path_p);
__attribute__ ((visibility ("default"))) extern int acl_extended_file_nofollow(const char *path_p);
__attribute__ ((visibility ("default"))) extern int acl_extended_fd(int fd);
__attribute__ ((visibility ("default"))) extern int acl_entries(acl_t acl);
__attribute__ ((visibility ("default"))) extern const char *acl_error(int code);
__attribute__ ((visibility ("default"))) extern int acl_get_perm(acl_permset_t permset_d, acl_perm_t perm);


struct error_context;
__attribute__ ((visibility ("default"))) extern int perm_copy_file (const char *, const char *,
       struct error_context *);
__attribute__ ((visibility ("default"))) extern int perm_copy_fd (const char *, int, const char *, int,
     struct error_context *);
__attribute__((visibility("hidden"))) int __acl_high_water_alloc(void **buf, size_t *bufsize, size_t newsize);

__attribute__((visibility("hidden"))) const char *__acl_quote(const char *str, const char *quote_chars);
__attribute__((visibility("hidden"))) char *__acl_unquote(char *str);

__attribute__((visibility("hidden"))) char *__acl_next_line(FILE *file);










static int acl_delete_file (const char * path, acl_type_t type);
static int list_acl(char *file);
static int set_acl(acl_t acl, acl_t dacl, const char *fname);
static int walk_dir(acl_t acl, acl_t dacl, const char *fname);

static char *program;
static int rflag;

static void
usage(void)
{
 fprintf(
        stderr
              , gettext("Usage:\n"));
 fprintf(
        stderr
              , gettext("\t%s acl pathname...\n"), program);
 fprintf(
        stderr
              , gettext("\t%s -b acl dacl pathname...\n"), program);
 fprintf(
        stderr
              , gettext("\t%s -d dacl pathname...\n"), program);
 fprintf(
        stderr
              , gettext("\t%s -R pathname...\n"), program);
 fprintf(
        stderr
              , gettext("\t%s -D pathname...\n"), program);
 fprintf(
        stderr
              , gettext("\t%s -B pathname...\n"), program);
 fprintf(
        stderr
              , gettext("\t%s -l pathname...\t[not IRIX compatible]\n"),
   program);
 fprintf(
        stderr
              , gettext("\t%s -r pathname...\t[not IRIX compatible]\n"),
   program);
 exit(1);
}

int
main(int argc, char *argv[])
{
 char *file;
 int switch_flag = 0;
 int args_required = 2;
 int failed = 0;
 int c;
 int dflag = 0;
 int bflag = 0;
 int Rflag = 0;
 int Dflag = 0;
 int Bflag = 0;
 int lflag = 0;
 acl_t acl = 
            ((void *)0)
                ;
 acl_t dacl = 
             ((void *)0)
                 ;

 program = 
          __xpg_basename
                  (argv[0]);

 setlocale(
          0
                  , "");
 setlocale(
          5
                     , "");
 bindtextdomain("acl", "/usr/share/locale");
 textdomain("acl");


 while ((c = getopt(argc, argv, "bdlRDBr")) != -1) {
  if (switch_flag)
   usage();
  switch_flag = 1;

  switch (c) {
   case 'b':
    bflag = 1;
    args_required = 3;
    break;
   case 'd':
    dflag = 1;
    args_required = 2;
    break;
   case 'R':
    Rflag = 1;
    args_required = 1;
    break;
   case 'D':
    Dflag = 1;
    args_required = 1;
    break;
   case 'B':
    Bflag = 1;
    args_required = 1;
    break;
   case 'l':
    lflag = 1;
    args_required = 1;
    break;
   case 'r':
    rflag = 1;
    args_required = 1;
    break;
   default:
    usage();
    break;
  }
 }


 if ((argc - optind) < args_required)
  usage();


 if (lflag) {
  for (; optind < argc; optind++) {
   file = argv[optind];
   if (!list_acl(file))
    failed++;
  }
  return(failed);
 }


 if (Rflag || Dflag || Bflag) {
  for (; optind < argc; optind++) {
   file = argv[optind];
   if (!Dflag &&
       (acl_delete_file(file, (0x8000)) == -1)) {
    fprintf(
           stderr
                 , gettext("%s: error removing access acl on \"%s\": %s\n")
                                                   ,
     program, file, strerror(
                            (*__errno_location ())
                                 ));
    failed++;
   }
   if (!Rflag &&
       (acl_delete_file(file, (0x4000)) == -1)) {
    fprintf(
           stderr
                 , gettext("%s: error removing default acl on \"%s\": %s\n")
                                                    ,
     program, file, strerror(
                            (*__errno_location ())
                                 ));
    failed++;
   }
  }
  return(failed);
 }


 if (! dflag) {
  acl = acl_from_text(argv[optind]);
  failed = acl_check(acl, &c);
  if (failed < 0) {
   fprintf(
          stderr
                , "%s: %s - %s\n",
    program, argv[optind], strerror(
                                   (*__errno_location ())
                                        ));
   return 1;
  }
  else if (failed > 0) {
   fprintf(
          stderr
                , gettext("%s: access ACL '%s': %s at entry %d\n")
                                            ,
    program, argv[optind], acl_error(failed), c);
   return 1;
  }
  optind++;
 }



 if (bflag || dflag) {
  dacl = acl_from_text(argv[optind]);
  failed = acl_check(dacl, &c);
  if (failed < 0) {
   fprintf(
          stderr
                , "%s: %s - %s\n",
    program, argv[optind], strerror(
                                   (*__errno_location ())
                                        ));
   return 1;
  }
  else if (failed > 0) {
   fprintf(
          stderr
                , gettext("%s: access ACL '%s': %s at entry %d\n")
                                            ,
    program, argv[optind], acl_error(failed), c);
   return 1;
  }
  optind++;
 }


 for (; optind < argc; optind++)
  failed += set_acl(acl, dacl, argv[optind]);

 if (acl)
  acl_free(acl);
 if (dacl)
  acl_free(dacl);

 return(failed);
}




static int
acl_delete_file(const char *path, acl_type_t type)
{
 int error = 0;


 if (type == (0x8000)) {
  acl_t acl;
  acl_entry_t entry;
  acl_tag_t tag;

  acl = acl_get_file(path, (0x8000));
  if (!acl)
   return -1;
  error = acl_get_entry(acl, 0, &entry);
  while (error == 1) {
   acl_get_tag_type(entry, &tag);
   switch(tag) {
    case (0x02):
    case (0x08):
    case (0x10):
     acl_delete_entry(acl, entry);
     break;
    }
   error = acl_get_entry(acl, 1, &entry);
  }
  if (!error)
   error = acl_set_file(path, (0x8000), acl);
 } else
  error = acl_delete_def_file(path);
 return(error);
}






static int
list_acl(char *file)
{
 acl_t acl = 
            ((void *)0)
                ;
 acl_t dacl = 
             ((void *)0)
                 ;
 char *acl_text, *dacl_text = 
                             ((void *)0)
                                 ;

 if ((acl = acl_get_file(file, (0x8000))) == 
                                                   ((void *)0)
                                                       ) {
  fprintf(
         stderr
               , gettext("%s: cannot get access ACL on '%s': %s\n"),
   program, file, strerror(
                          (*__errno_location ())
                               ));
  return 0;
 }
 if ((dacl = acl_get_file(file, (0x4000))) == 
                                                     ((void *)0) 
                                                          &&
     (
     (*__errno_location ()) 
           != 
              13
                    )) {
  fprintf(
         stderr
               , gettext("%s: cannot get default ACL on '%s': %s\n"),
   program, file, strerror(
                          (*__errno_location ())
                               ));
  return 0;
 }
 acl_text = acl_to_any_text(acl, 
                                ((void *)0)
                                    , ',', 0x10);
 if (acl_text == 
                ((void *)0)
                    ) {
  fprintf(
         stderr
               , gettext("%s: cannot get access ACL text on " "'%s': %s\n")
                , program, file, strerror(
                                         (*__errno_location ())
                                              ));
  return 0;
 }
 if (acl_entries(dacl) > 0) {
  dacl_text = acl_to_any_text(dacl, 
                                   ((void *)0)
                                       , ',', 0x10);
  if (dacl_text == 
                  ((void *)0)
                      ) {
   fprintf(
          stderr
                , gettext("%s: cannot get default ACL text on " "'%s': %s\n")
                 , program, file, strerror(
                                          (*__errno_location ())
                                               ));
   return 0;
  }
 }
 if (dacl_text) {
  printf("%s [%s/%s]\n", file, acl_text, dacl_text);
  acl_free(dacl_text);
 } else
  printf("%s [%s]\n", file, acl_text);
 acl_free(acl_text);
 acl_free(acl);
 acl_free(dacl);
 return 1;
}

static int
set_acl(acl_t acl, acl_t dacl, const char *fname)
{
 int failed = 0;

 if (rflag)
  failed += walk_dir(acl, dacl, fname);


 if (acl && acl_set_file(fname, (0x8000), acl) == -1) {
  fprintf(
         stderr
               , gettext("%s: cannot set access acl on \"%s\": %s\n"),
   program, fname, strerror(
                           (*__errno_location ())
                                ));
  failed++;
 }

 if (dacl && acl_set_file(fname, (0x4000), dacl) == -1) {
  fprintf(
         stderr
               , gettext("%s: cannot set default acl on \"%s\": %s\n"),
   program, fname, strerror(
                           (*__errno_location ())
                                ));
  failed++;
 }

 return(failed);
}

static int
walk_dir(acl_t acl, acl_t dacl, const char *fname)
{
 int failed = 0;
 DIR *dir;
 struct dirent64 *d;
 char *name;

 if ((dir = opendir(fname)) == 
                              ((void *)0)
                                  ) {
  if (
     (*__errno_location ()) 
           != 
              20
                     ) {
   fprintf(
          stderr
                , gettext("%s: opendir failed: %s\n"),
    program, strerror(
                     (*__errno_location ())
                          ));
   return(1);
  }
  return(0);
 }

 while ((d = readdir64(dir)) != 
                               ((void *)0)
                                   ) {

  if (strcmp(d->d_name, ".") == 0 || strcmp(d->d_name, "..") == 0)
   continue;

  name = malloc(strlen(fname) + strlen(d->d_name) + 2);
  if (name == 
             ((void *)0)
                 ) {
   fprintf(
          stderr
                , gettext("%s: malloc failed: %s\n"),
    program, strerror(
                     (*__errno_location ())
                          ));
   exit(1);
  }
  sprintf(name, "%s/%s", fname, d->d_name);

  failed += set_acl(acl, dacl, name);
  free(name);
 }
 closedir(dir);

 return(failed);
}
