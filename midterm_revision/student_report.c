#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student_report
{
    char date[11];
    char time[11];
    char userid[11];
    char questionid[11];
} report;

report a[1000000];

void merge(int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;
    report *l = (report*)malloc(n1 * sizeof(report));
    report *h = (report*)malloc(n2 * sizeof(report));
    int i1 = 0,i2 = 0;
    for (int i = 0; i < n1; i++) l[i] = a[i + low];
    for (int i = 0; i < n2; i++) h[i] = a[i + mid + 1];
    while (i1 < n1 && i2 < n2)
    {
        if (strcmp(l[i1].date,h[i2].date) < 0)
        {
            a[low++] = l[i1++];
        }
        else if (strcmp(l[i1].date,h[i2].date) > 0)
        {
            a[low++] = h[i2++];
        }
        else
        {
            a[low++] = l[i1++];
        }
    }
    while (i1 < n1)
    {
        a[low++] = l[i1++];
    }
    while (i2 < n2)
    {
        a[low++] = h[i2++];
    }
    free(l);
    free(h);
}

void merge_sort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(low, mid);
        merge_sort(mid + 1, high);
        merge(low,mid,high);
    }
}

int main()
{
    int i = 0;
    while (1)
    {
        scanf("%s",a[i].date);
        if (!strcmp(a[i].date,"*\0")) break;
        scanf("%s %s %s",a[i].time,a[i].userid,a[i].questionid);
        i++;
    }
    merge_sort(0, i - 1);
    int count = 1;
    report pre = a[0];
    for (int j = 1; j <= i; j++)
    {
        if (!strcmp(a[j].date, pre.date))
        {
            count++;
        }
        else
        {
            printf("%s %d\n",pre.date,count);
            count = 1;
            pre = a[j];
        }
    }
}