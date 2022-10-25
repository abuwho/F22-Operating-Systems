#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <string.h>

void * my_realloc(void * prev_ptr, size_t size) {
    void * ptr;

    size_t prev_size = malloc_usable_size(prev_ptr);

    if (prev_size == 0) {
        ptr = malloc(size);
        return ptr;
    }
    
    if (size == 0) free(prev_ptr);

    ptr = malloc(size);

    if (prev_size > size) memcpy(ptr, prev_ptr, size);
    else memcpy(ptr, prev_ptr, prev_size);
    
    free(prev_ptr);
    return ptr;
} 

int main() {
    return 0;
}