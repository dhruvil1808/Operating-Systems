#include <stdio.h>
#include <conio.h>
int main()
{
    int i, NOP, sum = 0, count = 0, y, quant, wait_time = 0, turn_around_time = 0, arr_time[10], burst_time[10], temp[10];
    float avg_wait_time, avg_turn_around_time;
    printf("Enter number of processes ");
    scanf("%d", &NOP);
    y = NOP;
    for (i = 0; i < NOP; i++)
    {
        printf("\n Enter the Arrival and Burst time of the Process[%d]\n", i + 1);
        printf(" Arrival time is: \t");
        scanf("%d", &arr_time[i]);
        printf(" \nBurst time is: \t");
        scanf("%d", &burst_time[i]);
        temp[i] = burst_time[i];
    }

    printf("Enter the Time Quantum for the process: \t");
    scanf("%d", &quant);

    printf("\n Process No \t\t Burst Time \t\t turn_around_time \t\t Waiting Time ");
    for (sum = 0, i = 0; y != 0;)
    {
        if (temp[i] <= quant && temp[i] > 0)
        {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        }
        else if (temp[i] > 0)
        {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }
        if (temp[i] == 0 && count == 1)
        {
            y--;
            printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i + 1, burst_time[i], sum - arr_time[i], sum - arr_time[i] - burst_time[i]);
            wait_time = wait_time + sum - arr_time[i] - burst_time[i];
            turn_around_time = turn_around_time + sum - arr_time[i];
            count = 0;
        }
        if (i == NOP - 1)
        {
            i = 0;
        }
        else if (arr_time[i + 1] <= sum)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }

    avg_wait_time = wait_time * 1.0 / NOP;
    avg_turn_around_time = turn_around_time * 1.0 / NOP;
    printf("\n Average Turn Around Time: \t%f", avg_wait_time);
    printf("\n Average Waiting Time: \t%f", avg_turn_around_time);
}