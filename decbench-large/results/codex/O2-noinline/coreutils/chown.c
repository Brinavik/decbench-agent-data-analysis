// Function: usage @ 0x31f0
#include <libintl.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

extern const char *program_name;
extern void emit_ancillary_info(const char *program);

#define usage(msgid) dcgettext(NULL, (msgid), LC_MESSAGES)

void
usage(int status)
{
    if (status != EXIT_SUCCESS) {
        fprintf(stderr, usage("Try '%s --help' for more information.\n"),
                program_name);
    } else {
        printf(usage("Usage: %s [OPTION]... [OWNER][:[GROUP]] FILE...\n"
                 "  or:  %s [OPTION]... --reference=RFILE FILE...\n"),
               program_name, program_name);
        fputs(usage("Change the owner and/or group of each FILE to OWNER and/or GROUP.\n"
                "With --reference, change the owner and group of each FILE to those of RFILE.\n"
                "\n"), stdout);
        fputs(usage("  -c, --changes          like verbose but report only when a change is made\n"
                "  -f, --silent, --quiet  suppress most error messages\n"
                "  -v, --verbose          output a diagnostic for every file processed\n"),
              stdout);
        fputs(usage("      --dereference      affect the referent of each symbolic link (this is\n"
                "                         the default), rather than the symbolic link itself\n"
                "  -h, --no-dereference   affect symbolic links instead of any referenced file\n"),
              stdout);
        fputs(usage("                         (useful only on systems that can change the\n"
                "                         ownership of a symlink)\n"), stdout);
        fputs(usage("      --from=CURRENT_OWNER:CURRENT_GROUP\n"
                "                         change the owner and/or group of each file only if\n"
                "                         its current owner and/or group match those specified\n"
                "                         here.  Either may be omitted, in which case a match\n"
                "                         is not required for the omitted attribute\n"), stdout);
        fputs(usage("      --no-preserve-root  do not treat '/' specially (the default)\n"
                "      --preserve-root    fail to operate recursively on '/'\n"), stdout);
        fputs(usage("      --reference=RFILE  use RFILE's owner and group rather than\n"
                "                         specifying OWNER:GROUP values\n"), stdout);
        fputs(usage("  -R, --recursive        operate on files and directories recursively\n"),
              stdout);
        fputs(usage("\n"
                "The following options modify how a hierarchy is traversed when the -R\n"
                "option is also specified.  If more than one is specified, only the final\n"
                "one takes effect.\n"
                "\n"
                "  -H                     if a command line argument is a symbolic link\n"
                "                         to a directory, traverse it\n"
                "  -L                     traverse every symbolic link to a directory\n"
                "                         encountered\n"
                "  -P                     do not traverse any symbolic links (default)\n"
                "\n"), stdout);
        fputs(usage("      --help        display this help and exit\n"), stdout);
        fputs(usage("      --version     output version information and exit\n"), stdout);
        fputs(usage("\n"
                "Owner is unchanged if missing.  Group is unchanged if missing, but changed\n"
                "to login group if implied by a ':' following a symbolic OWNER.\n"
                "OWNER and GROUP may be numeric as well as symbolic.\n"), stdout);
        printf(usage("\n"
                 "Examples:\n"
                 "  %s root /u        Change the owner of /u to \"root\".\n"
                 "  %s root:staff /u  Likewise, but also change its group to \"staff\".\n"
                 "  %s -hR root /u    Change the owner of /u and subfiles to \"root\".\n"),
               program_name, program_name, program_name);
        emit_ancillary_info("chown");
    }

    exit(status);
}


