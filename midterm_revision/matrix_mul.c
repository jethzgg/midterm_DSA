#include <stdio.h>

int main()
{
    int a[100][100],b[100][100],c[100][100];
    int n,k,m;
    scanf("%d %d",&n,&k);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    scanf("%d %d",&k,&m);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            c[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int t = 0; t < k; t++)
            {
                c[i][j] += a[i][t] * b[t][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}