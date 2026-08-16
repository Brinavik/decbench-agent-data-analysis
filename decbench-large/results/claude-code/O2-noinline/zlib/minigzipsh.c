// Function: main @ 0x1300
#include <stdio.h>
#include <string.h>

typedef struct gzFile_s *gzFile;

extern gzFile gzopen(const char *path, const char *mode);
extern gzFile gzdopen(int fd, const char *mode);

static char *prog;

static void error(const char *msg);
static void gz_compress(FILE *in, gzFile out);
static void gz_uncompress(gzFile in, FILE *out);
static void file_compress(char *file, char *mode);
static void file_uncompress(char *file);

int main(int argc, char *argv[]) {
    int copyout = 0;
    int uncompr = 0;
    gzFile file;
    char *bname, outmode[20];

    snprintf(outmode, sizeof(outmode), "%s", "wb6 ");

    prog = argv[0];
    bname = strrchr(argv[0], '/');
    if (bname)
        bname++;
    else
        bname = argv[0];
    argc--, argv++;

    if (!strcmp(bname, "gunzip"))
        uncompr = 1;
    else if (!strcmp(bname, "zcat"))
        copyout = uncompr = 1;

    while (argc > 0) {
        if (strcmp(*argv, "-c") == 0)
            copyout = 1;
        else if (strcmp(*argv, "-d") == 0)
            uncompr = 1;
        else if (strcmp(*argv, "-f") == 0)
            outmode[3] = 'f';
        else if (strcmp(*argv, "-h") == 0)
            outmode[3] = 'h';
        else if (strcmp(*argv, "-r") == 0)
            outmode[3] = 'R';
        else if ((*argv)[0] == '-' && (*argv)[1] >= '1' && (*argv)[1] <= '9' &&
                 (*argv)[2] == 0)
            outmode[2] = (*argv)[1];
        else
            break;
        argc--, argv++;
    }
    if (outmode[3] == ' ')
        outmode[3] = 0;
    if (argc == 0) {
        if (uncompr) {
            file = gzdopen(fileno(stdin), "rb");
            if (file == NULL) error("can't gzdopen stdin");
            gz_uncompress(file, stdout);
        } else {
            file = gzdopen(fileno(stdout), outmode);
            if (file == NULL) error("can't gzdopen stdout");
            gz_compress(stdin, file);
        }
    } else {
        do {
            if (uncompr) {
                if (copyout) {
                    file = gzopen(*argv, "rb");
                    if (file == NULL)
                        fprintf(stderr, "%s: can't gzopen %s\n", prog, *argv);
                    else
                        gz_uncompress(file, stdout);
                } else {
                    file_uncompress(*argv);
                }
            } else {
                if (copyout) {
                    FILE *in = fopen(*argv, "rb");

                    if (in == NULL) {
                        perror(*argv);
                    } else {
                        file = gzdopen(fileno(stdout), outmode);
                        if (file == NULL) error("can't gzdopen stdout");

                        gz_compress(in, file);
                    }
                } else {
                    file_compress(*argv, outmode);
                }
            }
        } while (argv++, --argc);
    }
    return 0;
}


