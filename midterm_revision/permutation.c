#include <stdio.h>

int a[3];

int check(int x, int k)
{
    for (int i = 0; i < (k-1); i++)
    {
        if (a[i] == x) return 0;
    }
    return 1;
}

void show(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void backtrack(int k,int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (check(i,k))
        {
            a[k - 1] = i;
            if (k == n)
            {
                show(n);
            }
            else
            {
                backtrack(k + 1,n);
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    backtrack(1,n);
    return 0;
}