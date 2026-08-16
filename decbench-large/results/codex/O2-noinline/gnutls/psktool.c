// Function: process_options @ 0x2ed0
#define _GNU_SOURCE
#include <errno.h>
#include <error.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int
process_options(int argc, char **argv)
{
    struct option_state {
        _Bool debug;
        _Bool keysize;
        _Bool username;
        _Bool pskfile;
        _Bool version;
        _Bool help;
        _Bool more_help;
        char *debug_arg;
        char *keysize_arg;
        char *username_arg;
        char *pskfile_arg;
        char *version_arg;
        int debug_value;
        int keysize_value;
        _Bool debug_given;
        _Bool keysize_given;
        _Bool username_given;
        _Bool pskfile_given;
        _Bool version_given;
        _Bool help_given;
        _Bool more_help_given;
    };
    extern struct option_state args_info;
    extern long parse_number(const char *text);
    extern void print_usage(FILE *stream, int status);

    static const struct option long_options[] = {
        { "debug",     required_argument, 0, 'd' },
        { "keysize",   required_argument, 0, 's' },
        { "username",  required_argument, 0, 'u' },
        { "pskfile",   required_argument, 0, 'p' },
        { "passwd",    required_argument, 0, 0x80 },
        { "version",   optional_argument, 0, 'v' },
        { "help",      no_argument,       0, 'h' },
        { "more-help", no_argument,       0, '!' },
        { 0, 0, 0, 0 }
    };

    int option;

    while ((option = getopt_long(argc, argv, "!d:hp:s:u:v:",
                                 long_options, NULL)) != -1) {
        switch (option) {
        case 0:
            break;

        case 'd':
            args_info.debug = 1;
            args_info.debug_arg = optarg;
            args_info.debug_value = (int)parse_number(optarg);
            args_info.debug_given = 1;
            break;

        case 's':
            args_info.keysize = 1;
            args_info.keysize_arg = optarg;
            args_info.keysize_value = (int)parse_number(optarg);
            args_info.keysize_given = 1;
            break;

        case 'u':
            args_info.username = 1;
            args_info.username_arg = optarg;
            args_info.username_given = 1;
            break;

        case 'p':
        case 0x80:
            args_info.pskfile = 1;
            args_info.pskfile_arg = optarg;
            args_info.pskfile_given = 1;
            break;

        case 'v':
            args_info.version = 1;
            args_info.version_arg = optarg;
            args_info.version_given = 1;
            break;

        case 'h':
            args_info.help = 1;
            args_info.help_given = 1;
            break;

        case '!':
            args_info.more_help = 1;
            args_info.more_help_given = 1;
            break;

        default:
            print_usage(stderr, 1);
            break;
        }
    }

    if (args_info.debug) {
        if (args_info.debug_value < 0)
            error(1, 0, "%s option value %d is out of range.",
                  "debug", args_info.debug_value);
        if (args_info.debug_value > 9999)
            error(1, 0, "%s option value %d is out of range",
                  "debug", args_info.debug_value);
    }

    if (args_info.keysize) {
        if (args_info.keysize_value < 0)
            error(1, 0, "%s option value %d is out of range.",
                  "keysize", args_info.keysize_value);
        if (args_info.keysize_value > 512)
            error(1, 0, "%s option value %d is out of range",
                  "keysize", args_info.keysize_value);
    }

    if (optind < argc)
        error(1, 0, "Command line arguments are not allowed.");

    if (args_info.help)
        print_usage(stdout, 0);

    if (args_info.more_help) {
        int pipefd[2];
        pid_t child;

        if (pipe(pipefd) < 0)
            error(1, errno, "pipe");

        child = fork();
        if (child == 0) {
            close(pipefd[0]);
            dup2(pipefd[1], STDOUT_FILENO);
            close(pipefd[1]);
            print_usage(stdout, 0);
        } else {
            char *pager;
            char *pager_argv[2];

            if (child < 0)
                error(1, errno, "fork");

            close(pipefd[1]);
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[0]);

            pager = secure_getenv("PAGER");
            if (pager == NULL || *pager == '\0')
                pager = "more";

            pager_argv[0] = pager;
            pager_argv[1] = NULL;
            execvp(pager, pager_argv);
            exit(1);
        }
    }

    if (args_info.version) {
        const char *version_text;

        if (args_info.version_arg == NULL ||
            strcmp(args_info.version_arg, "c") == 0) {
            version_text =
                "psktool 3.7.8\n"
                "Copyright (C) 2000-2021 Free Software Foundation, and others\n"
                "This is free software. It is licensed for use, modification and\n"
                "redistribution under the terms of the GNU General Public License,\n"
                "version 3 or later <http://gnu.org/licenses/gpl.html>\n\n"
                "Please send bug reports to:  <bugs@gnutls.org>            \n";
        } else if (strcmp(args_info.version_arg, "v") == 0) {
            version_text = "psktool 3.7.8\n";
        } else if (strcmp(args_info.version_arg, "n") == 0) {
            version_text =
                "psktool 3.7.8\n"
                "Copyright (C) 2000-2021 Free Software Foundation, and others\n"
                "This is free software. It is licensed for use, modification and\n"
                "redistribution under the terms of the GNU General Public License,\n"
                "version 3 or later <http://gnu.org/licenses/gpl.html>\n\n"
                "gnutls is free software: you can redistribute it and/or\n"
                "modify it under the terms of the GNU General Public License\n"
                "as published by the Free Software Foundation,\n"
                "either version 3 of the License, or (at your option) any later version.\n\n"
                "gnutls is distributed in the hope that it will be useful,\n"
                "but WITHOUT ANY WARRANTY; without even the implied warranty\n"
                "of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n"
                "See the GNU General Public License for more details.\n\n"
                "You should have received a copy of the GNU General Public License\n"
                "along with this program.  If not, see <http://www.gnu.org/licenses/>.\n\n"
                "Please send bug reports to:  <bugs@gnutls.org>            \n";
        } else {
            error(1, 0,
                  "version option argument 'a' invalid.  Use:\n"
                  "\t'v' - version only\n"
                  "\t'c' - version and copyright\n"
                  "\t'n' - version and full copyright notice");
            return optind;
        }

        fprintf(stdout, "%s", version_text);
        exit(0);
    }

    return optind;
}


