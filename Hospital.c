#include <stdio.h>
#include <string.h>
int main()
{
    int exe_time[20], arr_time[10], n, i, j, temp, p[10], s_time[10], f_time[10], wt[10], ta[10];
    char ch;
    int Total_WT = 0, Total_AT = 0;
    float awt, ata;
    char name[10][10], t[10];
    printf("Enter the number of patients:");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter patient name, arrival time, execution time, priority :");
        scanf("%s%d%d%d", name[i], &arr_time[i], &exe_time[i], &p[i]);
    }
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (p[i] > p[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
                temp = arr_time[i];
                arr_time[i] = arr_time[j];
                arr_time[j] = temp;
                temp = exe_time[i];
                exe_time[i] = exe_time[j];

                exe_time[j] = temp;
                strcpy(t, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], t);
            }
        }
    for (i = 0; i < n; i++)
    {
        if (i == 0)
        {
            s_time[i] = arr_time[i];
            wt[i] = s_time[i] - arr_time[i];
            f_time[i] = s_time[i] + exe_time[i];
            ta[i] = f_time[i] - arr_time[i];
        }
        else
        {
            s_time[i] = f_time[i - 1];
            wt[i] = s_time[i] - arr_time[i];
            f_time[i] = s_time[i] + exe_time[i];
            ta[i] = f_time[i] - arr_time[i];
        }
        Total_WT += wt[i];
        Total_AT += ta[i];
    }
    awt = (float)Total_WT / n;
    ata = (float)Total_AT / n;
    printf("\nname\tarrivaltime\texecutiontime\tpriority\twaitingtime\ttatime");
    for (i = 0; i < n; i++)
        printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d", name[i], arr_time[i], exe_time[i], p[i], wt[i], ta[i]);
    printf("\nAverage waiting time is:%f", awt);
    printf("\nAverage turnaroundtime is:%f", ata);
}