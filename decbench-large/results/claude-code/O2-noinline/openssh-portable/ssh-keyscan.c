// Function: argv_split @ 0x39a80
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/* allocation wrappers that abort on failure (never return NULL) */
extern void *xcalloc(size_t nmemb, size_t size);
extern void *xreallocarray(void *ptr, size_t nmemb, size_t size);

/*
 * Split a command string into an argv[] vector.
 *
 *   str    : input string
 *   argcp  : receives the number of arguments
 *   argvp  : receives a NULL-terminated, heap-allocated argv array
 *   flags  : if non-zero, a '#' at the start of a token begins a comment
 *
 * Returns 0 on success, -4 on argv_split (e.g. an unterminated quote).
 */
int argv_split(const char *str, int *argcp, char ***argvp, int flags)
{
	char **argv = xcalloc(1, sizeof *argv);
	int nargs = 0;
	int argc = 0;
	int i;

	*argvp = NULL;
	*argcp = 0;

	for (i = 0; str[i] != '\0'; ) {
		char c = str[i];
		char *word;
		int pos;
		char quote;

		if (c == ' ' || c == '\t') {
			i++;
			continue;
		}
		if (flags != 0 && c == '#') {
			argc = nargs;
			goto done;
		}

		/* start a new argument */
		argv = xreallocarray(argv, nargs + 2, sizeof *argv);
		word = xcalloc(1, strlen(&str[i]) + 1);
		argv[nargs] = word;
		argv[nargs + 1] = NULL;
		argc = nargs + 1;

		pos = 0;
		quote = 0;
		for (c = str[i]; c != '\0'; c = str[i]) {
			if (c == '\\') {
				char d = str[i + 1];

				if (d == '"' || d == '\'' || d == '\\'
				    || (d == ' ' && quote == 0)) {
					word[pos++] = d;
					i += 2;
				} else {
					word[pos++] = '\\';
					i++;
				}
			} else if (quote != 0) {
				if (c == quote)
					quote = 0;
				else
					word[pos++] = c;
				i++;
			} else if (c == ' ' || c == '\t') {
				break;			/* end of argument */
			} else if (c == '"' || c == '\'') {
				quote = c;
				i++;
			} else {
				word[pos++] = c;
				i++;
			}
		}

		if (c == '\0') {
			if (quote != 0) {
				/* unterminated quote: clean up and fail */
				int k;

				if (argv != NULL) {
					for (k = 0; k < argc; k++)
						free(argv[k]);
					free(argv);
				}
				return -4;
			}
			goto done;
		}

		nargs++;
	}
	argc = nargs;

done:
	*argcp = argc;
	*argvp = argv;
	return 0;
}


