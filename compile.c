#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>

#define CHUNK 1024

int main() {

    

    char *buf = malloc(chunk);

    if (buf == NULL) {
        /* deal with malloc() failure */
    }

    /* otherwise do this.  Note 'chunk' instead of 'sizeof buf' */
    while ((nread = fread(buf, 1, chunk, file)) > 0) {
        /* as above */
    }
}