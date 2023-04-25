//second chance page replacement algorithm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
int main()
{
    int n, f, i, j, k, page[MAX], frame[MAX], avail, count = 0, flag, pos, max, pf = 0;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &page[i]);
    printf("Enter the number of frames: ");
    scanf("%d", &f);
    for (i = 0; i < f; i++)
        frame[i] = -1;
    j = 0;
    printf("Page Replacement Process:   ");
    for (i = 0; i < n; i++)
    {
        printf("%d", page[i]);
        avail = 0;
        for (k = 0; k < f; k++)
            if (frame[k] == page[i])
                avail = 1;
        if (avail == 0)
        {
            frame[j] = page[i];
            j = (j + 1) % f;
            count = 0;
            pf++;
        }
        for (k = 0; k < f; k++)
            printf("\t%d", frame[k]);
    }
    printf("Number of Page Faults: %d", pf);
    return 0;
}
