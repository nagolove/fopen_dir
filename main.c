#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <errno.h>

void check_err() {
    if (errno) {
        printf("err: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
}

int main() {
    assert(errno == 0);
    FILE *f = fopen("/home/nagolove/", "r");
    check_err();
    assert(f);

    for (int i = 0; i < 10; i++) {
        printf("i %d\n", i);
        char *line = NULL;
        size_t len = 0;
        getline(&line, &len, f);
        if (line) {
            printf("'%s'\n", line);
            free(line);
        }
    }

    fclose(f);
}
