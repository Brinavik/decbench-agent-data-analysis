// Function: restore @ 0x5480
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libintl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define _(str) gettext(str)

#ifndef ACL_TYPE_ACCESS
#define ACL_TYPE_ACCESS  0x8000
#define ACL_TYPE_DEFAULT 0x4000
#endif

/* setfacl command codes (see parse.h) */
#define CMD_ENTRY_REPLACE 0
#define CMD_REMOVE_ACL    5

/* Flags for read_acl_seq(): SEQ_PARSE_WITH_PERM | SEQ_PARSE_DEFAULT |
   SEQ_PARSE_MULTI  == 0x31 */
#define SEQ_PARSE_FLAGS 0x31

typedef struct seq_entry *seq_t;

extern const char *progname;
extern int opt_test;

extern char *quote(const char *str);

extern seq_t seq_init(void);
extern int seq_free(seq_t seq);
extern int seq_append_cmd(seq_t seq, int cmd, int type);

extern int read_acl_comments(FILE *file, int *line, char **path_p,
			     uid_t *uid_p, gid_t *gid_p, mode_t *mode_p);
extern int read_acl_seq(FILE *file, seq_t seq, int cmd, int flags,
			int *line, int *which);
extern int do_set(const char *path_p, const struct stat *st,
		  int walk_flags, void *arg);

int
restore(FILE *file, const char *filename)
{
	char *path_p;
	uid_t uid;
	gid_t gid;
	mode_t mode, mask;
	struct stat st;
	seq_t seq = NULL;
	int line = 0, backup_line = 0;
	int mode_changed = 0;
	int status = 0;
	int error;

	memset(&st, 0, sizeof(st));

	for (;;) {
		error = read_acl_comments(file, &line, &path_p,
					  &uid, &gid, &mode);
		if (error < 0) {
			fprintf(stderr, _("%s: %s: %s\n"),
				progname, quote(filename), strerror(-error));
			status = 1;
			goto getout;
		}
		if (error == 0)
			return status;

		if (path_p == NULL) {
			if (filename)
				fprintf(stderr, _("%s: %s: No filename found "
					"in line %d, aborting\n"),
					progname, quote(filename), backup_line);
			else
				fprintf(stderr, _("%s: No filename found in "
					"line %d of standard input, "
					"aborting\n"),
					progname, backup_line);
			status = 1;
			goto getout;
		}

		seq = seq_init();
		if (seq == NULL ||
		    seq_append_cmd(seq, CMD_REMOVE_ACL, ACL_TYPE_ACCESS) ||
		    seq_append_cmd(seq, CMD_REMOVE_ACL, ACL_TYPE_DEFAULT)) {
			fprintf(stderr, _("%s: %s: %s\n"),
				progname, quote(filename), strerror(errno));
			status = 1;
			goto getout;
		}

		if (read_acl_seq(file, seq, CMD_ENTRY_REPLACE,
				 SEQ_PARSE_FLAGS, &line, NULL) != 0) {
			fprintf(stderr, _("%s: %s: %s in line %d\n"),
				progname, quote(filename), strerror(errno),
				line);
			status = 1;
			goto getout;
		}

		error = stat(path_p, &st);
		if (opt_test && error != 0) {
			fprintf(stderr, _("%s: %s: %s\n"),
				progname, quote(path_p), strerror(errno));
			status = 1;
		}

		mask = 0;
		if (do_set(path_p, &st, 0, &seq) == 0) {
			/* Restore the file owner and group. */
			if (uid != (uid_t)-1 && uid == st.st_uid)
				uid = (uid_t)-1;
			if (gid != (gid_t)-1 && gid == st.st_gid)
				gid = (gid_t)-1;
			if (!opt_test &&
			    (uid != (uid_t)-1 || gid != (gid_t)-1)) {
				if (chown(path_p, uid, gid) != 0) {
					fprintf(stderr, _("%s: %s: Cannot "
						"change owner/group: %s\n"),
						progname, quote(path_p),
						strerror(errno));
					status = 1;
				}
				/* chown may have cleared the set-user-ID and
				   set-group-ID bits;  restore them below. */
				if ((st.st_mode & mode) & (S_ISUID | S_ISGID))
					mode_changed = 1;
			}

			/* Restore the file mode if the special bits changed. */
			if (mode_changed ||
			    ((st.st_mode ^ mode) &
			     (S_ISUID | S_ISGID | S_ISVTX))) {
				if (mask == 0)
					mask = st.st_mode;
				mask &= 0777;
				if (chmod(path_p, mode | mask) != 0) {
					fprintf(stderr, _("%s: %s: Cannot "
						"change mode: %s\n"),
						progname, quote(path_p),
						strerror(errno));
					status = 1;
				}
			}
		} else
			status = 1;

		free(path_p);
		path_p = NULL;
		if (seq) {
			seq_free(seq);
			seq = NULL;
		}
		backup_line = line;
	}

getout:
	if (path_p)
		free(path_p);
	if (seq)
		seq_free(seq);
	return status;
}


