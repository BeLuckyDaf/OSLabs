#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void error(char* err) {
    printf("<error>: %s\n", err);
    exit(-1);
}

int main(int argc, char** argv) {
    int truncate = (argc > 2 && !strcmp(argv[1], "-a")) ? 0 : O_TRUNC;    
    if (truncate && argc < 2) error("file name is not specified.");

    size_t sz = argc - (truncate ? 1 : 2);
    int off = (truncate ? 1 : 2);
    int* fds = (int*)calloc(sz, sizeof(int));
    for (int i = 0; i < sz; i++) {
        fds[i] = open(argv[off + i], truncate | O_APPEND | O_CREAT | O_WRONLY, S_IRWXG | S_IRWXO | S_IRWXU);
    }

    char c;
    int f = open("/dev/stdin", O_RDONLY);
    while(read(f, &c, 1) && c != EOF) {
        for (int i = 0; i < sz; i++) write(fds[i], &c, 1);
    }
    close(f);

    for (int i = 0; i < sz; i++) close(fds[i]);

    return 0;
}