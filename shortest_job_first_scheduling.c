#include <stdio.h>

int main()
{
    int at[10], bt[10], temp[10];
    int i, sm, count = 0, time, limit;
    double wt = 0, tat = 0, end;
    float awt, avt;
    printf("\nEnter the Total Number of Processes:\t");
    scanf("%d", &limit);
    printf("\nEnter Details of %d Processes\n", limit);
    for (i = 0; i < limit; i++)
    {
        printf("\nEnter Arrival Time:\t");
        scanf("%d", &at[i]);
        printf("Enter Burst Time:\t");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }
    bt[9] = 9999;
    for (time = 0; count != limit; time++)
    {
        sm = 9;
        for (i = 0; i < limit; i++)
        {
            if (at[i] <= time && bt[i] < bt[sm] && bt[i] > 0)
            {
                sm = i;
            }
        }
        bt[sm]--;
        if (bt[sm] == 0)
        {
            count++;
            end = time + 1;
            wt = wt + end - at[sm] - temp[sm];
            tat = tat + end - at[sm];
        }
    }
    awt = wt / limit;
    avt = tat / limit;
    printf("\n\nAverage Waiting Time:\t%lf\n", awt);
    printf("Average Turnaround Time:\t%lf\n", avt);
    return 0;
}