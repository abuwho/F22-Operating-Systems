#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>


int main(int argc, char *argv[]){

    char ch, file_name[100] = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event in_event[64];
    int fp;
    size_t read_bytes;

    fp = open(file_name, O_RDONLY);

    FILE * output = fopen("ex3.txt", "w");
    printf("Available shortcuts:\np+e\nc+a+p\n");
    // TODO: Remember to run sudo command for ./ex3.out

    int pressed_keys[1024] = {0};

    while(1) { 
        read_bytes = read(fp, in_event, sizeof(in_event));
        for(int i = 0; i < (read_bytes/sizeof(struct input_event)); i++) {
            if (in_event[i].code == 58){
                return 0;
            }
            if (in_event[i].type == 1 && in_event[i].value == 1){
                pressed_keys[in_event[i].code] = 1;
            }
            else if (in_event[i].type == 1 && in_event[i].value == 0){
                pressed_keys[in_event[i].code] = 0;
            }
        }
        if ( pressed_keys[25] == 1 && pressed_keys[18] == 1 ){
            char *text = "I passed the Exam!\n";
            printf("I passed the Exam!\n");
            fprintf(output, "%s", text);
        }
        else if ( pressed_keys[46] == 1 && pressed_keys[30] == 1 && pressed_keys[25] == 1){
            char *text = "Get some cappuccino!\n";
            printf("Get some cappuccino!\n");
            fprintf(output, "%s", text);

        }
        else continue;
    }

    close(fp);
    fclose(output);
    return 0;
}
