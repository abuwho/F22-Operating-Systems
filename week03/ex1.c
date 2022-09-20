#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int foo(int age) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int yearNow = tm.tm_year + 1900;
    return yearNow - age;
}


int main()
{
    const int x = 10;
    const int *q = &x;    
    
    const int * const p = (const int *) malloc(5 * sizeof(int));
    int * nonConstPtr = p; // to modify values later
    for (int i = 0; i < 5; i++) *(nonConstPtr+i) = x;


    // Print the memory locations 
    for (int i = 0; i < 5; i++) printf("%p\n", p+i);
    // Print the values
    for (int i = 0; i < 5; i++) printf("%d\n", *(p+i));

    // Take input from user and store in the same cells
    for (int i = 0; i < 5; i++) {
        scanf("%d", (p+i));
    }

    // Printing ages
    printf("Age inputs: \n");
    for (int i = 0; i < 5; i++) printf("Age input %d = %d\n", i, *(p+i));

    for (int i = 0; i < 5; i++) {
        int age = *(p+i);
        int birthYear = foo(age);
        *(nonConstPtr+i) = birthYear;
    }

    printf("Printing birthyears: \n");
    for (int i = 0; i < 5; i++) printf("Birthyear %d = %d\n", i, *(p+i));


    // Freeing the allocated cells
    for (int i = 0; i < 5; i++) free(p+i);
    free(q);

    return 0;
}