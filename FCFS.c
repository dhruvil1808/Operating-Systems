#include <stdio.h>
int main()
{
        int n, burst_time[20], Wait_time[20], turn_around_time[20], avg_Wait_time = 0, avg_turn_around_time = 0, i, j;
        printf("Total number of processes: ");
        scanf("%d", &n);
        printf("Enter Burst time: ");
        for (i = 0; i < n; i++)
        {
                printf("P[%d]: ", i + 1);
                scanf("%d", &burst_time[i]);
        }
        Wait_time[0] = 0;
        for (i = 1; i < n; i++)
        {
                Wait_time[i] = 0;
                for (j = 0; j < i; j++)
                        Wait_time[i] += burst_time[j];
        }
        printf("\nProcess BurstTime WaitingTime TurnaroundTime");
        for (i = 0; i < n; i++)
        {
                turn_around_time[i] = burst_time[i] + Wait_time[i];
                avg_Wait_time += Wait_time[i];
                avg_turn_around_time += turn_around_time[i];
                printf("\nP[%d]\t\t%d\t\t%d\t\t%d", i + 1, burst_time[i], Wait_time[i], turn_around_time[i]);
        }
        avg_Wait_time /= i;
        avg_turn_around_time /= i;
        printf("\n\nAverage Waiting Time = %d", avg_Wait_time);
        printf("\nAverage Turnaround Time = %d", avg_turn_around_time);
        return 0;
}