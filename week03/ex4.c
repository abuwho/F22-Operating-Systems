#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*));

void* addInt(const void* a, const void* b){
    int sum = *((int*) a) + *((int*) b);
    int* re_turn = &sum;
    return (void*) re_turn;
}

void* addDouble(const void* a, const void* b){
    double sum = *((double*) a) + *((double*) b);
    double* re_turn = &sum;
    return (void*) re_turn;
}

void* mulInt(const void* a, const void* b){
        int product = *((int*) a) * *((int*) b);
        int* re_turn = &product;
        return (void*) re_turn;   
}

void* mulDouble(const void* a, const void* b){
        double product = *((double*) a) * *((double*) b);
        double* re_turn = &product;
        return (void*) re_turn;
}

void* meanInt(const void* a, const void* b){
    //<WRITE YOUR CODE HERE>;
}

void* meanDouble(const void* a, const void* b){
    //<WRITE YOUR CODE HERE>;
}

void* aggregate(void* base, size_t size, int n, void* initial_value, void* (*opr)(const void*, const void*)){

	void* output;

	if (size==sizeof(int)){ // base is a pointer to an integer
        if (opr == meanInt) {
            output = aggregate(base, size, n, initial_value, &addInt);
            int re_turn = *((int*) output) / n;
            output = &re_turn;
        } else {
            int initial = *((int*) initial_value);
            output = &initial;
            for (int i = 0; i < n; i++) {
                output = opr(output, ((int*) base + i));
            }
        }

	} else { // base is a pointer to a double
        if (opr == meanDouble) {
            output = aggregate(base, size, n, initial_value, &addDouble);
            double re_turn = *((double*) output) / n;
            output = &re_turn;
        } else {
            double initial = *((double*) initial_value);
            output = &initial;
            for(int i = 0; i < n; i++) {
                output = opr(output, ((double*) base + i));
            }
        }   
	}
	return output;
}



int main() {
    int n = 5;
    int* ints = malloc(sizeof(int) * 5);
    double* doubles = malloc(sizeof(double) * 5);

    // Populating the memory cells
    for (int i = 0; i < 5; i++) *(ints + i) = i*23 + 17;
    for (int i = 0; i < 5; i++) *(doubles + i) = pow(3.9, i);

    // Set initial values
    int addIntInitVal = 0;
    int* addIntInitPtr = &addIntInitVal;
    double addDoubleInitVal = 0.0;
    double* addDoubleInitPtr = &addDoubleInitVal;
    int mulIntInitVal = 1;
    int* mulIntInitPtr = &mulIntInitVal;
    double mulDoubleInitVal = 1.0;
    double* mulDoubleInitPtr = &mulDoubleInitVal;

    // Addition
    int* result1a = aggregate(ints, sizeof (int), n, addIntInitPtr, &addInt);
    printf("%d\n", *result1a);
    double* result2a = aggregate(doubles, sizeof (double), n, addDoubleInitPtr, &addDouble);
    printf("%f\n", *result2a);

    // Multiplication
    int* result1m = aggregate(ints, sizeof (int), n, mulIntInitPtr, &mulInt);
    printf("%d\n", *result1m);
    double* result2m = aggregate(doubles, sizeof (double), n, mulDoubleInitPtr, &mulDouble);
    printf("%f\n", *result2m);

    // Mean
    int* result1mean = aggregate(ints, sizeof (int), n, addIntInitPtr, &meanInt);
    printf("%d\n", *result1mean);
    double* result2mean = aggregate(doubles, sizeof (double), n, addDoubleInitPtr, &meanDouble);
    printf("%f\n", *result2mean);

    // Free pointers
    free(ints);
    free(doubles);

    return EXIT_SUCCESS;
}