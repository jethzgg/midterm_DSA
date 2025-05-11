#include <stdio.h>

int check[15],a[15][15],sum = 0,count = 0,result[15];

void backtrack(int k, int n, int m)
{
    for (int i = 1; i < n; i++)
    {
        if (!check[i] && ((sum + a[result[k - 2] - 1][i]) <= m))
        {
            check[i] = 1;
            sum += a[result[k - 2] - 1][i];
            result[k - 1] = i + 1;
            if (k == n)
            {
                printf("%d\n",sum);
                if ((sum + a[i][0]) <= m) count += 1;
            }
            else
            {
                backtrack(k + 1,n,m);
            }
            sum -= a[result[k - 2] - 1][i];
            result[k - 1] = 0;
            check[i] = 0;
        }
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < n; i++)
    {
        check[i] = 0;
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    result[0] = 1;
    check[0] = 1;
    backtrack(2,n,m);
    printf("%d\n",count);
    return 0;
}