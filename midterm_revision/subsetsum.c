#include <stdio.h>

int a[50], check[50], sum = 0, count = 0, tmp = 0;

void backtrack(int k, int n, int b)
{
    for (int i = tmp; i < n; i++)
    {
        if (!check[i] && (sum + a[i]) <= b) //branch and bound
        {
            sum += a[i];
            check[i] = 1;
            if (k == n || sum == b)
            {
                if (sum == b) count++;
            }
            else
            {
                tmp = i + 1; //before backtrack to the next element
                backtrack(k + 1, n, b);
            }
            sum -= a[i];
            check[i] = 0;
        }
    }
}

int main()
{
    int n,b;
    scanf("%d %d", &n, &b);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
        check[i] = 0;
    }
    backtrack(1,n,b);
    printf("%d\n",count);
    return 0;
}