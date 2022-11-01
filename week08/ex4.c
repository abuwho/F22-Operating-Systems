#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/resource.h>

int main() 
{

    void * ptr[10];
    struct rusage usage;

    for (int i = 0; i < 10; i++) {
        
        ptr[i] = malloc(10*1024*1024);

        if (ptr[i] != NULL) memset(ptr[i], 0, 10*1024*1024);

        getrusage(RUSAGE_SELF, &usage);

        printf("Usage: %ld\n", usage.ru_maxrss);
        
        sleep(1);

    }

    for (int i = 0; i < 10; i++) free(ptr[i]);

    getrusage(RUSAGE_SELF, &usage);
    printf("Usage after freeing the memory: %ld\n", usage.ru_maxrss);

    return 0;
}

