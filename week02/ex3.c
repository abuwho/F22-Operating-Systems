#include <stdio.h>
#include <string.h>


// converts from decimal to any base
void convert(long long num, int source, int target) {
    
    long long decimalNum = num;
    long long result = 0;
    int rem, temp = 1;

    while (decimalNum != 0)
    {
        rem = decimalNum % target;
        decimalNum = decimalNum / target;
        result = result + rem * temp;
        temp = temp * 10;
    }

    printf("%ld\n", result);
}


int val(char c) {
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

long long to_decimal(char *str, int base)
{

    int len = strlen(str);
    int power = 1; // Initialize power of base
    long long num = 0;  // Initialize result
    int i;
 
    // Decimal equivalent is str[len-1]*1 +
    // str[len-2]*base + str[len-3]*(base^2) + ...
    for (i = len - 1; i >= 0; i--)
    {
        // A digit in input number must be
        // less than number's base
        if (val(str[i]) >= base)
        {
           printf("Invalid Number");
           return -1;
        }
 
        num += val(str[i]) * power;
        power = power * base;
    }
 
    return num;
}






int main(void)
{
    
    long long ll = to_decimal("3EC", 16);
    convert(ll, 8, 16);

    printf("%d\n", val('2'));


    return 0;
}