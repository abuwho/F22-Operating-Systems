#include <stdio.h>
#include <limits.h>

int main(void)
{
    int i = INT_MAX;
    unsigned short us = USHRT_MAX;
    signed long sl = LONG_MAX;
    float f = __FLT_MAX__;
    double d = __DBL_MAX__;    

    printf("int = %d\tsizeof(int) = %lu\n", i, sizeof(i));
    printf("unsigned short = %hu\tsizeof(unsigned short) = %lu\n", us, sizeof(us));
    printf("signed long = %li\tsizeof(signed long) = %lu\n", sl, sizeof(sl));
    printf("float = %f\tsizeof(float) = %lu\n", f, sizeof(f));
    printf("double = %lf\tsizeof(double) = %lu\n", d, sizeof(d));

    return 0;
}