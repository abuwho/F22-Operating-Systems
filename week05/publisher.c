#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>


int main(int argc, char* argv[])
{
    int fd;

    // FIFO file path
    char * fifo = "/tmp/ex1";

    mkfifo(fifo, 0777);

    char message[200];
    fd = open(fifo, O_WRONLY);

    int n = atoi(argv[0]);

    while (1) {
        fgets(message, 200, stdin);
        for (int i = 0; i < n; i++) {
            write(fd, message, strlen(message) + 1);
            sleep(n);
        }
    }

    close(fd);
    return 0;
}

// mkfifo reference
// https://man7.org/linux/man-pages/man3/mkfifo.3.html