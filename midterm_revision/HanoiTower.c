#include <stdio.h>

int count = 0, f[1100000], t[1100000];

void tower(int nums, int from, int to, int inter)
{
    if (nums == 1)
    {
        f[count] = from;
        t[count++] = to;
    }
    else
    {
        tower(nums - 1, from, inter, to);
        tower(1, from, to, inter);
        tower(nums - 1, inter, to, from);
    }
}

int main()
{
    int n, a, b, c;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    tower(n,a,b,c);
    printf("%d\n", count);
    for (int i = 0; i < count; i++)
    {
        printf("%d %d\n", f[i], t[i]);
    }
    return 0;
}