#include <stdio.h>
int main()
{
    int pn = 0;
    int CPU = 0;
    int allTime = 0;
    printf("Enter number of processes: ");
    scanf("%d", &pn);
    int AT[pn];
    int ATt[pn];
    int NoP = pn;
    int PT[pn];
    int PP[pn];
    int waittingTime[pn];
    int turnaroundTime[pn];

    for (int i = 0; i < pn; i++)
    {
        printf("\nProcessing time for P%d: ", i + 1);
        scanf("%d", &PT[i]);
        printf("Priority for P%d: ", i + 1);
        scanf("%d", &PP[i]);
        printf("Arrival Time for P%d: ", i + 1);
        scanf("%d", &AT[i]);
        ATt[i] = AT[i];
    }

    int LAT = 0;
    for (int i = 0; i < pn; i++)
        if (AT[i] > LAT)
            LAT = AT[i];

    int ATv = AT[0];
    int ATi = 0;
    int P1 = PP[0];
    int P2 = PP[0];

    while (NoP > 0 && CPU <= 1000)
    {
        for (int i = 0; i < pn; i++)
        {
            if (ATt[i] < ATv)
            {
                ATi = i;
                ATv = ATt[i];
                P1 = PP[i];
                P2 = PP[i];
            }
            else if (ATt[i] == ATv || ATt[i] <= CPU)
            {
                if (PP[i] != (pn + 1))
                    P2 = PP[i];
                if (P2 < P1)
                {
                    ATi = i;
                    ATv = ATt[i];
                    P1 = PP[i];
                    P2 = PP[i];
                }
            }
        }
        if (CPU < ATv)
        {
            CPU = CPU + 1;
            continue;
        }
        else
        {

            waittingTime[ATi] = CPU - ATt[ATi];
            CPU = CPU + PT[ATi];
            turnaroundTime[ATi] = CPU - ATt[ATi];
            ATt[ATi] = LAT + 10;
            ATv = LAT + 10;
            ATi = 0;
            PP[ATi] = pn + 1;
            P1 = PP[0];
            P2 = PP[0];
            printf("Iam in");
            NoP = NoP - 1;
        }
    }

    printf("\nPN\tPT\tPP\tWT\tTT\n\n");
    for (int i = 0; i < pn; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, PT[i], PP[i], waittingTime[i], turnaroundTime[i]);
    }

    int AvgWT = 0;
    int AVGTaT = 0;
    for (int i = 0; i < pn; i++)
    {
        AvgWT = waittingTime[i] + AvgWT;
        AVGTaT = turnaroundTime[i] + AVGTaT;
    }

    printf("AvgWaittingTime = %d\nAvgTurnaroundTime = %d\n", AvgWT / pn, AVGTaT / pn);
}