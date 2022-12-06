#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main()
{

    FILE * input = fopen("input.txt", "r");

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    int amount_types = 0;
    int processes = 0;
    int E[128] = {0};
    int A[128] = {0};
    int C[128][128];
    int R[128][128];
    memset(C, 0, sizeof(C));
    memset(R, 0, sizeof(R));

    // E
    if ((read = getline(&line, &len, input)) != -1){
        char* p = line;
        while (*p) {
            if ( isdigit(*p) ) {
                E[amount_types] = strtol(p, &p, 10);
                amount_types++;
            } else { p++; }
        }
    } else { exit (-1); }
    getline(&line, &len, input);

    // A
    read = getline(&line, &len, input);
    char* p = line;
    for (int i = 0; i < amount_types; i++) {
        while (!isdigit(*p)){
            p++;
        }
        A[amount_types] = strtol(p, &p, 10);
    }
    getline(&line, &len, input);

    // C
    do {
        getline(&line, &len, input);
        char* p = line;
        for (int i = 0; i < amount_types; i++){
            while (!isdigit(*p)){
                p++;
            }
            C[processes][i] = strtol(p, &p, 10);
        }
        processes++;
    } while ( strlen(line) > 2 );
    processes--;

    // R
    for (int j = 0; j < processes; j++) {
        getline(&line, &len, input);
        char* p = line;
        for (int i = 0; i < amount_types; i++) {
            while (!isdigit(*p)){
                p++;
            }
            R[j][i] = strtol(p, &p, 10);
        }
    }


    int deadlocked = processes;
    int marked[128] = {0};
    for (int i = 0; i < processes; i++){
        int good = 0;
        for (int j = 0; j < processes; j++){
            if ( marked[j] == 0 ){
                good = 1;
                for (int k = 0; k < amount_types; k++){
                    if (R[j][k] > A[k]){
                        good = 0;
                    }
                }
                if (good == 1) {
                    marked[j] = 1;
                    deadlocked--;
                    for (int k = 0; k < amount_types; k++){
                        A[k] += C[j][k];
                    }
                    break;
                }
            }
        }
    }

    if (deadlocked > 0){
        printf("%d", deadlocked);
    }
    else {
        printf("No deadlocked processes");
    }

    return 0;
}
