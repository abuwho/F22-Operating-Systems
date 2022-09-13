#include <stdio.h>
#include <string.h>


// To count number of occurrences of a character
int count(char str[], char c) {
    int result = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (toupper(str[i]) == toupper(c)) {
            result++;
        }
    }
    return result;
}


// To count number of occurrences of each character 
int countAll(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        int count_i = count(str, str[i]);
        printf("%c:%d", tolower(str[i]), count_i);
        if (i != strlen(str) - 1) {
            printf(", ");
        }
    }
}


int main(void)
{
    char p = 'p';
    int p_count = count("innopolis", 'p');
    printf("%c:%d", p, p_count);
    printf("\n");
    countAll("Innopolis");
    return 0;
}