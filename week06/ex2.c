#include <stdio.h>
#include <string.h>
#include <limits.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arrivals[n], bursts[n], completions[n], turnarounds[n], waitings[n], ready[n], exec[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arrivals[i], &bursts[i]);
    }

    int turnaround_total = 0, waiting_total = 0; 
    int timer = 0, finished = 0;

    for (int i = 0; i < n; i++) {
        ready[i] = 0;
        exec[i] = 0;
    }

    while (finished < n) {
        for (int i = 0; i < n; i++) {
            if (arrivals[i] <= timer && !ready[i]) {
                ready[i] = 1;
            }
        }
        int best_process = -1, mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!exec[i] && ready[i] && bursts[i] < mini) {
                mini = bursts[i];
                best_process = i;
            }
        }
        if (best_process != -1) {
            completions[best_process] = timer + bursts[best_process];
            turnarounds[best_process] = completions[best_process] - arrivals[best_process];
            waitings[best_process] = turnarounds[best_process] - bursts[best_process];
            turnaround_total += turnarounds[best_process];
            waiting_total += waitings[best_process];
            timer += bursts[best_process];
            finished += 1;
            exec[best_process] = 1;
        } else {
            timer++;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("\nProcess #%d:\nExecution = %d\nTurnaround = %d\nWaiting = %d\n", i, completions[i], turnarounds[i], waitings[i]);
    }
    
    double turnaround_avg = (double) turnaround_total / n;
    double waiting_avg = (double) waiting_total / n;

    printf("Average Turnaround time = %lf\nAverage waiting time = %lf\n", turnaround_avg, waiting_avg);

    return 0;
}
