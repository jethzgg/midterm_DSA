#include <stdio.h>
#include <stdlib.h>

int a[100][100];

int check(int n)
{
    int *rows = (int*)calloc(n,sizeof(int));
    int *cols = (int*)calloc(n,sizeof(int));
    int *ups = (int*)calloc(2 * n + 1,sizeof(int));
    int *downs = (int*)calloc(2 * n + 1,sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == 1)
            {
                if (rows[i] != 0)
                {
                    return 0;
                }
                rows[i]++;
                if (cols[j] != 0)
                {
                    return 0;
                }
                cols[j]++;
                if (ups[i + j] != 0)
                {
                    return 0;
                }
                ups[i + j]++;
                if (downs[i - j + n - 1] != 0)
                {
                    return 0;
                }
                downs[i - j + n - 1]++;
            }
        }
    }
    return 1;
}

int main()
{
    int n,T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        printf("%d\n",check(n));
    }
    return 0;    
}