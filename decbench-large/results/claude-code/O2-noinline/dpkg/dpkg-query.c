// Function: pkg_array_match_patterns @ 0x5720
#include <stdbool.h>
#include <stdlib.h>

/* dpkg internal types (opaque layouts recovered from the binary) */

struct pkgbin;

struct pkginfo {
	char _pad[0x48];
	struct pkgbin *installed;	/* &pkg->installed lives at offset 0x48 */
};

struct pkg_array {
	int n_pkgs;
	struct pkginfo **pkgs;
};

struct pkg_spec {
	char _opaque[0x28];		/* 40 bytes */
};

enum pkg_spec_flags {
	PKG_SPEC_PATTERNS      = (1 << 0),
	PKG_SPEC_ARCH_WILDCARD = (1 << 9),
};

typedef void pkg_array_visitor_func(struct pkg_array *array,
                                    struct pkginfo *pkg, void *pkg_data);

extern void *m_malloc(size_t size);
extern void *m_calloc(size_t nmemb, size_t size);

extern void pkg_spec_init(struct pkg_spec *ps, enum pkg_spec_flags flags);
extern void pkg_spec_parse(struct pkg_spec *ps, const char *str);
extern bool pkg_spec_match_pkg(struct pkg_spec *ps, struct pkginfo *pkg,
                               struct pkgbin *pkgbin);
extern void pkg_spec_destroy(struct pkg_spec *ps);

extern void pkg_array_foreach(struct pkg_array *array,
                              pkg_array_visitor_func *visitor, void *pkg_data);

extern void notice(const char *fmt, ...);

extern const char *gettext(const char *msgid);
#define pkg_array_match_patterns(str) gettext(str)

int
pkg_array_match_patterns(struct pkg_array *array,
         pkg_array_visitor_func *pkg_visitor, void *pkg_data,
         const char *const *argv)
{
	int argc, i, ip;
	int rc = 0;
	struct pkg_spec *ps;
	int *found;

	for (argc = 0; argv[argc]; argc++)
		;

	found = m_calloc(argc, sizeof(found[0]));

	ps = m_malloc(sizeof(*ps) * argc);
	for (i = 0; i < argc; i++) {
		pkg_spec_init(&ps[i], PKG_SPEC_PATTERNS | PKG_SPEC_ARCH_WILDCARD);
		pkg_spec_parse(&ps[i], argv[i]);
	}

	for (ip = 0; ip < array->n_pkgs; ip++) {
		struct pkginfo *pkg = array->pkgs[ip];
		bool pkg_found = false;

		for (i = 0; i < argc; i++) {
			if (pkg_spec_match_pkg(&ps[i], pkg,
			                       (struct pkgbin *)&pkg->installed)) {
				found[i]++;
				pkg_found = true;
			}
		}

		if (!pkg_found)
			array->pkgs[ip] = NULL;
	}

	pkg_array_foreach(array, pkg_visitor, pkg_data);

	for (i = 0; i < argc; i++) {
		if (found[i] == 0) {
			notice(pkg_array_match_patterns("no packages found matching %s"), argv[i]);
			rc++;
		}
		pkg_spec_destroy(&ps[i]);
	}

	free(ps);
	free(found);

	return rc;
}


