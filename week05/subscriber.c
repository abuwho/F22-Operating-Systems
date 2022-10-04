#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int main() {

    int fd1;

    char * fifo = "/tmp/ex1";
    mkfifo(fifo, 0666);
    char message[200];

    while(1) {
        fd1 = open(fifo, O_RDONLY);
        read(fd1, message, 200);

        printf("%s", message);
        close(fd1);
    }

    return 0;
}


// mkfifo reference 
// https://man7.org/linux/man-pages/man3/mkfifo.3.html