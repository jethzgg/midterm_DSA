#include <stdio.h>
#include <stdlib.h>

int n, a[12][12], rows[12], cols[12], ups[25], downs[25], result[12], count = 0, b[12][12];

int Init(int a[12][12])
{
    for (int i = 0; i < n; i++)
    {
        rows[i] = 0;
        cols[i] = 0;
        result[i] = -1;
    }

    for (int i = 0; i < (2 * n + 1); i++)
    {
        ups[i] = 0;
        downs[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n ; j++)
        {
            if (a[i][j] == 1)
            {
                rows[i] = 1;
                cols[j] = 1;
                ups[i + j] = 1;
                downs[j - i + n - 1] = 1;
            }
        }
    }
}

int check(int i, int j)
{
    if (rows[i]) return 0;
    if (cols[j]) return 0;
    if (ups[i + j]) return 0;
    if (downs[j - i + n - 1]) return 0;
    return 1;
}

void backtrack(int k)
{
    for (int i = 0; i < n ; i++)
    {
        if (b[k][i])
        {
            if (k == n - 1)
            {
                count++;
            }
            else 
            {
                backtrack(k + 1);
            }
        }
        else
        {
            if (check(k,i))
            {
                result[k] = i;
                a[k][i] = 1;
                rows[k] = 1;
                cols[i] = 1;
                ups[k + i] = 1;
                downs[i - k + n - 1] = 1;
                if (k == n - 1)
                {
                    count++;
                }
                else 
                {
                    backtrack(k + 1);
                }
                result[k] = -1;
                a[k][i] = 0;
                rows[k] = 0;
                cols[i] = 0;
                ups[k + i] = 0;
                downs[i - k + n - 1] = 0;
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n ; j++)
        {
            scanf("%d",&a[i][j]);
            if (a[i][j]) b[i][j] = 1;
            else b[i][j] = 0;
        }
    }
    Init(a);
    backtrack(0);
    printf("%d\n",count);
    return 0;
}