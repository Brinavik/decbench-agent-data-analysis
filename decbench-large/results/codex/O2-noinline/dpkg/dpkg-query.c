// Function: pkg_array_match_patterns @ 0x5720
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <libintl.h>

struct pkgbin {
    unsigned char _opaque;
};

struct pkginfo {
    unsigned char _header[0x48];
    struct pkgbin available;
};

struct pkg_array {
    int n_pkgs;
    struct pkginfo **pkgs;
};

struct pkg_spec {
    char *name;
    void *arch;
    int flags;
    bool name_is_pattern;
    bool arch_is_pattern;
    void *pkg_iter;
    void *arch_iter;
};

enum pkg_spec_flags {
    PKG_SPEC_NAME_WILDCARD = 0x001,
    PKG_SPEC_ARCH_WILDCARD = 0x200
};

typedef void pkg_array_apply_func(struct pkg_array *, struct pkginfo *, void *);

extern void *m_malloc(size_t size);
extern void *m_calloc(size_t nmemb, size_t size);
extern void pkg_spec_init(struct pkg_spec *spec, int flags);
extern const char *pkg_spec_parse(struct pkg_spec *spec, const char *text);
extern bool pkg_spec_match_pkg(const struct pkg_spec *spec,
                               const struct pkginfo *pkg,
                               const struct pkgbin *pkgbin);
extern void pkg_spec_destroy(struct pkg_spec *spec);
extern void pkg_array_foreach(struct pkg_array *array,
                              pkg_array_apply_func *func, void *data);
extern void warning(const char *format, ...);

int
pkg_array_match_patterns(struct pkg_array *array, pkg_array_apply_func *func, void *data,
         const char *const patterns[])
{
    struct pkg_spec *specs;
    int *matches;
    int n_patterns = 0;
    int i;
    int unmatched = 0;

    while (patterns[n_patterns] != NULL)
        n_patterns++;

    matches = m_calloc(n_patterns, sizeof(*matches));
    specs = m_malloc(n_patterns * sizeof(*specs));

    for (i = 0; i < n_patterns; i++) {
        pkg_spec_init(&specs[i],
                      PKG_SPEC_NAME_WILDCARD | PKG_SPEC_ARCH_WILDCARD);
        pkg_spec_parse(&specs[i], patterns[i]);
    }

    for (i = 0; i < array->n_pkgs; i++) {
        struct pkginfo *pkg = array->pkgs[i];
        bool matched = false;
        int j;

        for (j = 0; j < n_patterns; j++) {
            if (pkg_spec_match_pkg(&specs[j], pkg, &pkg->available)) {
                matches[j]++;
                matched = true;
            }
        }

        if (!matched)
            array->pkgs[i] = NULL;
    }

    pkg_array_foreach(array, func, data);

    for (i = 0; i < n_patterns; i++) {
        if (matches[i] == 0) {
            warning(dcgettext(NULL, "no packages found matching %s", 5),
                    patterns[i]);
            unmatched++;
        }
        pkg_spec_destroy(&specs[i]);
    }

    free(specs);
    free(matches);

    return unmatched;
}


