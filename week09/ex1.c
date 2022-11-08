#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


int page_frames;
int *page_table;
int page_counter[1000];
int hit, miss;


int main(int argc, char *argv[]) {

    FILE * input_file = fopen("input.txt", "r");

    page_frames = atoi(argv[1]);

    page_table = (unsigned int *)calloc(page_frames, sizeof(int));

    int page;
    while (fscanf(input_file, "%d", &page) == 1) {
        int found = 0;
        for (int i = 0; i < page_frames; i++) {
            if (page == page_table[i]) {
                hit++;
                found = 1;
                break;
            }
        }

        if (found == 0) {
            miss++;
            unsigned int swap_count = UINT_MAX;
            int swap_at = 0;

            for (int i = 0; i < page_frames; i++) {
                int cand = page_counter[page_table[i]];
                if (cand < swap_count) swap_count = cand, swap_at = i;
            }
            
            page_table[swap_at] = page;
        }

        for (int i = 0; i < 1000; i++) page_counter[i] >>= 1;

        page_counter[page] |= 1 << (32 - 1);
    }


    printf("Hit ratio for %d = %.2f%%\n", page_frames, 100.0 * hit / miss);

    return 0;
}