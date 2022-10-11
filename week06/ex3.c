#include <stdio.h>
#include <string.h>

int main()
{
    int n, quantum;
    scanf("%d %d", &n, &quantum);
    int arrivals[n], bursts[n], burst_tmp[n], waitings[n], completions[n], turnarounds[n], exec[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arrivals[i], &bursts[i]);
        burst_tmp[i] = bursts[i];
    }

    int turnaround_total = 0, waiting_total = 0, current_process = 0, finished = 0, timer = 0;
    
    for (int i = 0; i < n; i++) {
        exec[i] = 0;
    }

    while (finished < n) {
        if (exec[current_process] == 0 && arrivals[current_process] <= timer) {
            if (bursts[current_process] <= quantum) {
                completions[current_process] = timer + bursts[current_process];
                turnarounds[current_process] = completions[current_process] - arrivals[current_process];
                waitings[current_process] = turnarounds[current_process] - burst_tmp[current_process];
                turnaround_total += turnarounds[current_process];
                waiting_total += waitings[current_process];
                timer += bursts[current_process];
                finished += 1;
                exec[current_process] = 1;
            } else {
                timer += quantum;
                bursts[current_process] -= quantum;
            }
        } else {
            timer += 1;
        }
        current_process++;
        if (current_process == n) {
            current_process = 0;
        }
    }

    double turnaround_avg = (double) turnaround_total / n;
    double waiting_avg = (double) waiting_total / n;

    for (int i = 0; i < n; i++) {
        printf("\nProcess #%d:\nExecution = %d\nTurnaround = %d\nWaiting = %d\n", i, completions[i], turnarounds[i], waitings[i]);
    }

    printf("Average Turnaround time = %lf\nAverage waiting time = %lf\n", turnaround_avg, waiting_avg);

    return 0;
}
