#include <stdio.h>

int main(void)
{

    // pattern 1
    printf("Pattern 1: \n");
    for (int i = 1; i <= 7; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }


    // pattern 2
    printf("\nPattern 2: \n");
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    for (int i = 3; i >= 1; i--) {
        for (int j = i; j >= 1; j--) {
            printf("*");
        }
        printf("\n");
    }


    // pattern 3
    printf("\nPattern 3: \n");
    for (int i = 1; i <= 7; i++) {
        printf("*******\n");
    }
    printf("\n");

    return 0;
}