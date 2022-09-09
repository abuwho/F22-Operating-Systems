#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[256], reversedStr[256];

    char buff = getchar();
    int i = 0;

    while (buff != '.' && buff != '\0' && buff != '\n') {
        str[i] = buff;
        i++;
        buff = getchar();
    }
    str[i] = '\0';

    // Reverses the string.
    for (int j = strlen(str); j >= 0; j--) {
        reversedStr[strlen(str) - j] = str[j-1];
    }
    
    printf("\"%s\"", reversedStr);
    return 0;
}