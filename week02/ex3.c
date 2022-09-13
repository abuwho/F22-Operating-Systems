#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Determining the value for 
int val(char c) {
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

long long to_decimal(char str[], int src)
{

    int len = strlen(str);
    int power = 1;
    long long res = 0;
    int i;
 
    for (i = len - 1; i >= 0; i--) {
        if (val(str[i]) >= src) {
           return -1;
        }
        res += val(str[i]) * power;
        power = power * src;
    }
 
    return res;
}


// converts from decimal to any base
int convert(long long num, int source, int target) {
    char str_num[256];
    itoa(num, str_num, 10);
    long long decimalNum = to_decimal(str_num, source);
    
    // checks for foul input
    if (decimalNum == -1) {
        printf("cannot convert!");
        return 0;
    }
    long long result = 0;
    int rem, temp = 1;

    while (decimalNum != 0) {   rem = decimalNum % target;
        decimalNum = decimalNum / target;
        result = result + rem * temp;
        temp = temp * 10;
    }

    printf("%ld\n", result);
}



int main()
{
    long long inputNum;
    int source, target;

    scanf("%ld %d %d", &inputNum, &source, &target);
    

    // checks for wrong input
    if (source < 2 || source > 10 || target < 2 || target > 10) {
        printf("cannot convert!");
        return 0;
    }
    
    convert(inputNum, source, target);

    return 0;
}