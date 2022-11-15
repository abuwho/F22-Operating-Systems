#include<stdio.h> 
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
  
int main()
{
    DIR* dir = opendir("tmp"); 
    if (dir == NULL){ 
        printf("Directory /tmp doesn't exist.\n"); 
        return EXIT_FAILURE; 
    }


    // TODO:

  
     return EXIT_SUCCESS; 
 }