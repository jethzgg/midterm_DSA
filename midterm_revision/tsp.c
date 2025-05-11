#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int visited[20], n, a[20][20], min = INT_MAX, result[21], sum = 0;

void travel(int k)
{
    for (int i = 1; i < n; i++)
    {
        if (!visited[i] && (sum + a[result[k - 1] - 1][i]) <= min)
        {
            visited[i]++;
            result[k] = i + 1;
            sum += a[result[k - 1] - 1][i];
            if (k == n - 1)
            {
                if ((sum + a[i][0]) < min)
                {
                    min = sum + a[i][0];
                }
            }
            else
            {
                travel(k + 1);
            }
            visited[i]--;
            result[k] = 0;
            sum -= a[result[k - 1] - 1][i];
        }
    }
}

int main()
{
    result[0] = 1;
    result[n] = 1;
    visited[0] = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    travel(1);
    printf("%d\n",min);
    return 0;
}