#include <stdio.h>
#define modulo 1000000007
int n, a[100001];

int main()
{
    a[0] = 0, a[1] = 1;
    scanf("%d",&n);
    for (int i = 2; i <= n; i++)
    {
        a[i] = (a[i - 1] + a[i - 2]) % modulo;
    }
    printf("%d\n", a[n]);
    return 0;
}