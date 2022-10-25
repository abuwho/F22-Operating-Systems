#include <stdio.h>

int main () {
    char ** ptr;
    char * foo = "Hello World";
    ptr = &foo;

    printf("s is %p\n", ptr);
    
    ptr[0] = foo;
    
    printf("s[0] is %s\n", ptr[0]);
    
    return (0);
}