#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

// Calculate the current time in milliseconds
long long getCurrentTime() {
    struct timeval t;
    gettimeofday(&t, NULL);
    long long time = t.tv_sec*1000 + t.tv_usec/1000;
    return time;
}


int main(void)
{
    pid_t pid = fork();
    long long initTime = getCurrentTime();
    if (pid != 0) {
        pid = fork();
        initTime = getCurrentTime();
        if (pid == 0) {
            printf("Child process (ID: %d) | Parent ID: %d\n", getpid(), getppid());
        } else {
            printf("Parent process (ID: %d) | Parent ID: %d\n", getpid(), getppid());
        }
    } else {
        initTime = getCurrentTime();
        printf("Child process (ID: %d) | Parent ID: %d\n", getpid(), getppid());
    }
    
    long long exec_time = getCurrentTime() - initTime;

    printf("Execution time for process %d = %lld\n", getpid(), exec_time);

    return EXIT_SUCCESS;
}