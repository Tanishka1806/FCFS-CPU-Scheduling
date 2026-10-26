
#include <stdio.h>

int main()
{
    int n, i, j, temp;
    int pid[20], at[20], bt[20];
    int ct[20], tat[20], wt[20];
    int time = 0;

    float total_wt = 0;
    float total_tat = 0;

    printf("====================================\n");
    printf(" FCFS CPU SCHEDULING ALGORITHM\n");
    printf("====================================\n");

    printf("Enter number of processes (1-20): ");
    scanf("%d", &n);

    if (n < 1 || n > 20)
    {
        printf("Invalid number of processes!\n");
        return 1;
    }

    /* Input arrival and burst times */
    for (i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        printf("\nEnter Arrival Time for P%d: ", pid[i]);
        scanf("%d", &at[i]);

        printf("Enter Burst Time for P%d: ", pid[i]);
        scanf("%d", &bt[i]);

        if (at[i] < 0 || bt[i] <= 0)
        {
            printf("Invalid input! Arrival time must be >= 0 "
                   "and burst time must be > 0.\n");
            return 1;
        }
    }

    /* Sort processes by arrival time */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (at[i] > at[j])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    /* Calculate scheduling times */
    for (i = 0; i < n; i++)
    {
        /* CPU waits if no process has arrived */
        if (time < at[i])
        {
            time = at[i];
        }

        ct[i] = time + bt[i];
        time = ct[i];

        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_wt += wt[i];
        total_tat += tat[i];
    }

    /* Display results */
    printf("\n\n");
    printf("=============== FCFS RESULT ===============\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    printf("-------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i],
               ct[i], tat[i], wt[i]);
    }

    printf("-------------------------------------------\n");

    printf("\nAverage Waiting Time = %.2f\n",
           total_wt / n);

    printf("Average Turnaround Time = %.2f\n",
           total_tat / n);

    /* Display Gantt chart */
    printf("\nGantt Chart:\n");

    printf("|");
    for (i = 0; i < n; i++)
    {
        printf("  P%d  |", pid[i]);
    }

    printf("\n%d", (time = (ct[0] - bt[0])));

    for (i = 0; i < n; i++)
    {
        printf("\t%d", ct[i]);
    }

    printf("\n\nProgram executed successfully!\n");

    return 0;
}

