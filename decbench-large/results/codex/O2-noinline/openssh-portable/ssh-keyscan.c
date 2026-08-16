// Function: argv_split @ 0x39a80
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

extern void *xcalloc(size_t, size_t);
extern void *xreallocarray(void *, size_t, size_t);

int
argv_split(const char *s, int *argcp, char ***argvp,
    int terminate_on_comment)
{
	int argc = 0, quote, i, j;
	char *arg, **argv = xcalloc(1, sizeof(*argv));

	*argcp = 0;
	*argvp = NULL;

	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] == ' ' || s[i] == '\t')
			continue;
		if (terminate_on_comment && s[i] == '#')
			break;

		argv = xreallocarray(argv, argc + 2, sizeof(*argv));
		arg = argv[argc++] = xcalloc(1, strlen(s + i) + 1);
		argv[argc] = NULL;

		for (j = 0, quote = 0; s[i] != '\0'; i++) {
			if (quote == 0 && (s[i] == ' ' || s[i] == '\t'))
				break;
			if (quote != 0 && s[i] == quote) {
				quote = 0;
				continue;
			}
			if (quote == 0 && (s[i] == '\"' || s[i] == '\'')) {
				quote = s[i];
				continue;
			}
			if (s[i] == '\\' &&
			    (s[i + 1] == '\"' || s[i + 1] == '\'' ||
			    s[i + 1] == '\\' ||
			    (quote == 0 && s[i + 1] == ' ')))
				i++;
			arg[j++] = s[i];
		}
		if (quote != 0) {
			for (j = 0; j < argc; j++)
				free(argv[j]);
			free(argv);
			return -4;
		}
	}

	*argcp = argc;
	*argvp = argv;
	return 0;
}


