#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {

    void * ptr[20];

    for (int i = 0; i < 20; i++) {
        
        ptr[i] = malloc(100*1024*1024);

        if (ptr[i] != NULL) memset(ptr[i], 0, 100*1024*1024);
        
        sleep(1);

    }

    for (int i = 0; i < 20; i++) free(ptr[i]);

    return 0;
}

/*

Explanation: 

si: Memory that is swapped in every second from disk in kilobytes.
so: Memory that is swapped out every second to disk in kilobytes.

From the vmstat report we can see that, every second a considerable amount of virtual memory is created (and filled with data). 
Therefore, both occassional increasing and decreasing trend can be observed in "si" field. 

*/