#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pthread.h>
#include <string.h>


struct Thread {
    int id;
    int i;
    char message[256];
};

void * f(void * args) {
    struct Thread * thread = (struct Thread *) args;
    printf("Thread #%d: %s\n", thread->id, thread->message);
}

int main(){
    int n;
    scanf("%d", &n);

    struct Thread threads[n];

    for (int i = 0; i < n; i++) {
        struct Thread thread;

        thread.i = i;
        thread.id = i;

        char str[] = "Hello from thread ";
        char numStr[32];

        sprintf(numStr, "%d", i);
        strcat(str, numStr);
        strcpy(thread.message, str);

        threads[i] = thread;
    }

    pthread_t pthreads[n];

    for (int i = 0; i < n; i++) {
        if (pthread_create(&pthreads[i], NULL, &f, &threads[i]) != 0) {
            printf("Error: failed to create thread #%d!\n", i);
            return 0;
        }
        printf("Created thread #%d.\n", i);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(pthreads[i], NULL);
    }
    // Yes, the threads print the messages according the order that they were created in.

	return EXIT_SUCCESS;
}
