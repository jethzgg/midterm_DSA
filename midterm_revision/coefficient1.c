#include <stdio.h>

int a[10], sum = 0;

int show(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void backtrack(int k, int n, int m)
{
    for (int i = 1; i <= (m - n + 1); i++)
    {
        if (sum < m)
        {
            a[k - 1] = i;
            sum += i;
            if (k == n)
            {
                if (sum == m) show(n);
            }
            else
            {
                backtrack(k + 1,n,m);
            }
            sum -= i;
        }
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    backtrack(1,n,m);
    return 0;
}