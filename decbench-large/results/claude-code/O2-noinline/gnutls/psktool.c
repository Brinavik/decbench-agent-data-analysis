// Function: process_options @ 0x2ed0
#define _GNU_SOURCE

#include <errno.h>
#include <error.h>
#include <getopt.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct psktool_options
{
  /* Options present in the command line */
  struct
  {
    bool debug;
    bool keysize;
    bool username;
    bool pskfile;
    bool version;
    bool help;
    bool more_help;
  } present;

  /* Option arguments in raw string form */
  struct
  {
    const char *debug;
    const char *keysize;
    const char *username;
    const char *pskfile;
    const char *version;
  } arg;

  /* Option arguments parsed as integer */
  struct
  {
    int debug;
    int keysize;
  } value;

  /* Option enablement status */
  struct
  {
    bool debug;
    bool keysize;
    bool username;
    bool pskfile;
    bool version;
    bool help;
    bool more_help;
  } enabled;
};

#define HAVE_OPT(name) HAVE_OPT_ ## name
#define HAVE_OPT_DEBUG psktool_options.present.debug
#define HAVE_OPT_KEYSIZE psktool_options.present.keysize
#define HAVE_OPT_USERNAME psktool_options.present.username
#define HAVE_OPT_PSKFILE psktool_options.present.pskfile
#define HAVE_OPT_VERSION psktool_options.present.version
#define HAVE_OPT_HELP psktool_options.present.help
#define HAVE_OPT_MORE_HELP psktool_options.present.more_help
#define OPT_ARG_VERSION psktool_options.arg.version
#define OPT_VALUE_DEBUG psktool_options.value.debug
#define OPT_VALUE_KEYSIZE psktool_options.value.keysize
#define USAGE(status) usage (stdout, (status))

struct psktool_options psktool_options;

long parse_number (const char *arg);
void usage (FILE *out, int status);

/* Long options.  */
static const struct option long_options[] =
{
  { "debug", required_argument, 0, 'd' },
  { "keysize", required_argument, 0, 's' },
  { "username", required_argument, 0, 'u' },
  { "pskfile", required_argument, 0, 'p' },
  { "passwd", required_argument, 0, CHAR_MAX + 1 },
  { "version", optional_argument, 0, 'v' },
  { "help", no_argument, 0, 'h' },
  { "more-help", no_argument, 0, '!' },
  { 0, 0, 0, 0 }

};

int
process_options (int argc, char **argv)
{
  struct psktool_options *opts = &psktool_options;
  int opt;


  while ((opt = getopt_long (argc, argv, "!d:hp:s:u:v:",
                             long_options, NULL)) != EOF)
    switch (opt)
      {
      case '\0': /* Long option.  */
        break;
      case 'd':
        opts->present.debug = true;
        opts->arg.debug = optarg;
        opts->value.debug = parse_number(optarg);
        opts->enabled.debug = true;
        break;
      case 's':
        opts->present.keysize = true;
        opts->arg.keysize = optarg;
        opts->value.keysize = parse_number(optarg);
        opts->enabled.keysize = true;
        break;
      case 'u':
        opts->present.username = true;
        opts->arg.username = optarg;
        opts->enabled.username = true;
        break;
      case 'p':
      case CHAR_MAX + 1: /* --passwd */
        opts->present.pskfile = true;
        opts->arg.pskfile = optarg;
        opts->enabled.pskfile = true;
        break;
      case 'v':
        opts->present.version = true;
        opts->arg.version = optarg;
        opts->enabled.version = true;
        break;
      case 'h':
        opts->present.help = true;
        opts->enabled.help = true;
        break;
      case '!':
        opts->present.more_help = true;
        opts->enabled.more_help = true;
        break;
      default:
        usage (stderr, EXIT_FAILURE);
        break;
      }

  if (HAVE_OPT(DEBUG) && OPT_VALUE_DEBUG < 0)
    {
      error (EXIT_FAILURE, 0, "%s option value %d is out of range.",
             "debug", opts->value.debug);
    }
  if (HAVE_OPT(DEBUG) && OPT_VALUE_DEBUG > 9999)
    {
      error (EXIT_FAILURE, 0, "%s option value %d is out of range",
             "debug", opts->value.debug);
    }
  if (HAVE_OPT(KEYSIZE) && OPT_VALUE_KEYSIZE < 0)
    {
      error (EXIT_FAILURE, 0, "%s option value %d is out of range.",
             "keysize", opts->value.keysize);
    }
  if (HAVE_OPT(KEYSIZE) && OPT_VALUE_KEYSIZE > 512)
    {
      error (EXIT_FAILURE, 0, "%s option value %d is out of range",
             "keysize", opts->value.keysize);
    }
  if (optind < argc)
    {
      error (EXIT_FAILURE, 0, "Command line arguments are not allowed.");
    }


  if (HAVE_OPT(HELP))
    {
      USAGE(0);
    }

  if (HAVE_OPT(MORE_HELP))
    {
      pid_t pid;
      int pfds[2];

      if (pipe (pfds) < 0)
        error (EXIT_FAILURE, errno, "pipe");

      pid = fork ();
      if (pid < 0)
        error (EXIT_FAILURE, errno, "fork");

      if (pid == 0)
        {
          close (pfds[0]);
          dup2 (pfds[1], STDOUT_FILENO);
          close (pfds[1]);

          usage (stdout, 0);
        }
      else
        {
          const char *args[2];
          const char *envvar;

          close (pfds[1]);
          dup2 (pfds[0], STDIN_FILENO);
          close (pfds[0]);

          envvar = secure_getenv ("PAGER");
          if (!envvar || *envvar == '\0')
            args[0] = "more";
          else
            args[0] = envvar;

          args[1] = NULL;

          execvp (args[0], (char * const *)args);

          exit (EXIT_FAILURE);
        }
    }

  if (HAVE_OPT(VERSION))
    {
      if (!OPT_ARG_VERSION || !strcmp (OPT_ARG_VERSION, "c"))
        {
          const char str[] =
            "psktool 3.7.8\n"
            "Copyright (C) 2000-2021 Free Software Foundation, and others\n"
            "This is free software. It is licensed for use, modification and\n"
            "redistribution under the terms of the GNU General Public License,\n"
            "version 3 or later <http://gnu.org/licenses/gpl.html>\n"
            "\n"
            "Please send bug reports to:  <bugs@gnutls.org>            \n";
          fprintf (stdout, "%s", str);
          exit(0);
        }
      else if (!strcmp (OPT_ARG_VERSION, "v"))
        {
          const char str[] =
            "psktool 3.7.8\n";
          fprintf (stdout, "%s", str);
          exit(0);
        }
      else if (!strcmp (OPT_ARG_VERSION, "n"))
        {
          const char str[] =
            "psktool 3.7.8\n"
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
          fprintf (stdout, "%s", str);
          exit(0);
        }
      else
        {
          error (EXIT_FAILURE, 0,
                 "version option argument 'a' invalid.  Use:\n"
                 "	'v' - version only\n"
                 "	'c' - version and copyright\n"
                 "	'n' - version and full copyright notice");
        }
    }

  return optind;
}


