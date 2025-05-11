#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[4];
    float s,min = 1000000000.0;
    while (n)
    {
        for (int i = 0; i < 4; i++)
        {
            scanf("%d",&a[i]);
        }
        s = sqrt(fabs(a[0] - a[2]) * fabs(a[0] - a[2]) + fabs(a[1] - a[3]) * fabs(a[1] - a[3])) * sqrt(fabs(a[0] - a[2]) * fabs(a[0] - a[2]) + fabs(a[1] - a[3]) * fabs(a[1] - a[3])) / 2;
        if (s < min) min = s;
        n--;
    }
    printf("%f\n",min);
    return 0;
}