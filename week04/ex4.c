#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(void){
	char command[128];

    while (1) {
        scanf("%s", command);
        system(command);
    }

	return EXIT_SUCCESS;
}


// Example on using system
// https://www.codingunit.com/c-reference-stdlib-h-function-system

// Example on using execve
// https://linuxhint.com/c-execve-function-usage/
