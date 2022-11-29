#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/input.h>


int main(int argc, char *argv[]) 
{
    char ch, file_name[100] = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    struct input_event in_event[64];
    int fp;
    size_t read_bytes;

    fp = open(file_name, O_RDONLY);
    
    // TODO: Remember to run sudo command for ./ex2.out

    while(1) { 
        read_bytes = read(fp, in_event, sizeof(in_event));
        for(int i = 0; i < (read_bytes/sizeof(struct input_event)); i++) {
            if (in_event[i].code == 58){
                return 0;
            }
            if (in_event[i].type == 1 && in_event[i].value == 1){
                printf("PRESSED: 0x%x (%d)\n", in_event[i].code, in_event[i].code);
            }
            else if (in_event[i].type == 1 && in_event[i].value == 0){
                printf("RELEASED: 0x%x (%d)\n", in_event[i].code, in_event[i].code);
            }
        }
    }

    close(fp);
    return 0;
}
