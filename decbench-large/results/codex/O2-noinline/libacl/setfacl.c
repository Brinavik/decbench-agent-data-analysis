// Function: restore @ 0x5480
#include <errno.h>
#include <libintl.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct command_sequence command_sequence;

struct do_set_args {
    command_sequence *seq;
    mode_t mode;
};

enum {
    SEQ_REMOVE_ACL = 5,
    SEQ_PARSE_RESTORE = 0x31,
    ACL_TYPE_DEFAULT = 0x4000,
    ACL_TYPE_ACCESS = 0x8000
};

extern int test_mode;
extern const char *program_name;

extern int read_restore_entry(FILE *, int *, char **, uid_t *, gid_t *, mode_t *);
extern command_sequence *seq_init(void);
extern int seq_append(command_sequence *, int, int);
extern int parse_acl(FILE *, command_sequence *, int, int, int *, int *);
extern int do_set(const char *, const struct stat *, int, struct do_set_args *);
extern void seq_free(command_sequence *);
extern const char *quote_filename(const char *);

int restore(FILE *file, const char *input_name)
{
    struct stat st = { 0 };
    struct do_set_args args = { 0 };
    char *path = NULL;
    uid_t uid;
    gid_t gid;
    mode_t flags = 0;
    int entry_line = 0;
    int line = 0;
    int status = 0;

    for (;;) {
        int result;

        result = read_restore_entry(file, &line, &path, &uid, &gid, &flags);
        if (result <= 0) {
            if (result < 0) {
                fprintf(stderr, "%s: %s: %s\n", program_name,
                        quote_filename(input_name), strerror(-result));
                status = 1;
            }
            break;
        }

        if (path == NULL) {
            if (input_name != NULL) {
                fprintf(stderr,
                        dcgettext(NULL,
                                  "%s: %s: No filename found in line %d, aborting\n",
                                  LC_MESSAGES),
                        program_name, quote_filename(input_name), entry_line);
            } else {
                fprintf(stderr,
                        dcgettext(NULL,
                                  "%s: No filename found in line %d of standard input, aborting\n",
                                  LC_MESSAGES),
                        program_name, entry_line);
            }
            status = 1;
            break;
        }

        args.seq = seq_init();
        if (args.seq == NULL ||
            seq_append(args.seq, SEQ_REMOVE_ACL, ACL_TYPE_ACCESS) != 0 ||
            seq_append(args.seq, SEQ_REMOVE_ACL, ACL_TYPE_DEFAULT) != 0) {
            fprintf(stderr, "%s: %s: %s\n", program_name,
                    quote_filename(input_name), strerror(errno));
            status = 1;
            break;
        }

        if (parse_acl(file, args.seq, 0, SEQ_PARSE_RESTORE, &line, NULL) != 0) {
            fprintf(stderr,
                    dcgettext(NULL, "%s: %s: %s in line %d\n", LC_MESSAGES),
                    program_name, quote_filename(input_name), strerror(errno), line);
            status = 1;
            break;
        }

        if (stat(path, &st) != 0 && test_mode) {
            fprintf(stderr, "%s: %s: %s\n", program_name,
                    quote_filename(path), strerror(errno));
            status = 1;
        }

        args.mode = 0;
        if (do_set(path, &st, 0, &args) == 0) {
            int ownership_changed;
            int force_chmod = 0;

            if (uid != (uid_t)-1 && uid == st.st_uid)
                uid = (uid_t)-1;
            if (gid != (gid_t)-1 && gid == st.st_gid)
                gid = (gid_t)-1;

            ownership_changed = uid != (uid_t)-1 || gid != (gid_t)-1;
            if (!test_mode && ownership_changed) {
                if (chown(path, uid, gid) != 0) {
                    fprintf(stderr,
                            dcgettext(NULL,
                                      "%s: %s: Cannot change owner/group: %s\n",
                                      LC_MESSAGES),
                            program_name, quote_filename(path), strerror(errno));
                    status = 1;
                }
                force_chmod = (flags & st.st_mode & (S_ISUID | S_ISGID)) != 0;
            }

            if (force_chmod || ((flags ^ st.st_mode) & 07000) != 0) {
                if (args.mode == 0)
                    args.mode = st.st_mode;
                args.mode &= 0777;
                if (chmod(path, args.mode | flags) != 0) {
                    fprintf(stderr,
                            dcgettext(NULL,
                                      "%s: %s: Cannot change mode: %s\n",
                                      LC_MESSAGES),
                            program_name, quote_filename(path), strerror(errno));
                    status = 1;
                }
            }
        } else {
            status = 1;
        }

        free(path);
        path = NULL;
        seq_free(args.seq);
        args.seq = NULL;
        entry_line = line;
    }

    free(path);
    if (args.seq != NULL)
        seq_free(args.seq);
    return status;
}


