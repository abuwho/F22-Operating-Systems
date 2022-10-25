#include<stdio.h>
#include<stdlib.h>

int main(){
    int N;
    scanf("%d", &N);

    int * ptr = (int*) malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++) {
        ptr[i] = i;
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", ptr[i]);
    }
    
    free(ptr);
}