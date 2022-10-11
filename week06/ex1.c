#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arrivals[n], bursts[n], completions[n], turnarounds[n], waitings[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arrivals[i], &bursts[i]);
    }

    int turnaround_total = 0, waiting_total = 0, current_time = 0;

    for (int i = 0; i < n; i++) {
        if (arrivals[i] > current_time) {
            current_time = arrivals[i];
        }
        completions[i] = current_time + bursts[i];
        turnarounds[i] = completions[i] - arrivals[i];
        waitings[i] = turnarounds[i] - bursts[i];
        turnaround_total += turnarounds[i];
        waiting_total += waitings[i];
        current_time += bursts[i];
    }

    
    double turnaround_avg = (double) turnaround_total / n;
    double waiting_avg = (double) waiting_total / n;

    for (int i = 0; i < n; i++) {
        printf("\nProcess #%d:\nExecution = %d\nTurnaround = %d\nWaiting = %d\n", i, completions[i], turnarounds[i], waitings[i]);
    }

    printf("Average turnaround = %lf\nAverage waiting = %lf\n", turnaround_avg, waiting_avg);

    return 0;
}
