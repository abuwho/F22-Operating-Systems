#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int main() {
    int fd[2];

    if (pipe(fd) == -1) {
        puts("Error: pipe could not be opened.");
    }

    pid_t publisher = fork();

    if (publisher == 0) {
        char message[200];
        while(1) {
            fgets(message, 200, stdin);
            write(fd[1], &message, 200 * sizeof(char));
        }
    } else {
        char message[200];
        while(1) {
            read(fd[0], &message, 200 * sizeof(char));
            printf("Received message: \"%s\"", message);
        }
    }

    return 0;
}



// pipe reference 
// https://man7.org/linux/man-pages/man2/pipe.2.html