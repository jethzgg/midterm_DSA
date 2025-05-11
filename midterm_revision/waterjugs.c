#include <stdio.h>

int gcd(int a, int b)
{
    while (a != b)
    {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

int pour(int a_max, int b_max, int c_max)
{
    int a = a_max, b = 0, count = 1;
    while (b != c_max)
    {
        if ((b + a) > b_max)
        {
            a -= (b_max - b);
            b = b_max;
            count++;
        }
        else
        {
            b += a;
            a = 0;
            count++;
        }
        if (b == c_max || a == c_max)
        {
            return count;
        }
        if (a == 0)
        {
            count++;
            a = a_max;
        }
        if (b == b_max)
        {
            b = 0; 
            count++;
        }
    }
    return count;
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    #include <stdio.h>

int gcd(int a, int b)
{
    while (a != b)
    {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

int pour(int a_max, int b_max, int c_max)
{
    int a = a_max, b = 0, count = 1;
    while (a != c_max && b != c_max)
    {
        if ((b + a) > b_max)
        {
            a -= (b_max - b);
            b = b_max;
            count++;
        }
        else
        {
            b += a;
            a = 0;
            count++;
        }
        if (b == c_max || a == c_max)
        {
            return count;
        }
        if (a == 0)
        {
            count++;
            a = a_max;
        }
        if (b == b_max)
        {
            b = 0; 
            count++;
        }
    }
    return count;
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if (c % gcd(a,b))
    {
        printf("-1");
    }
    else
    {
        printf("%d",pour(a,b,c));
    }
    return 0;
}
    if (c % gcd(a,b))
    {
        printf("-1");
    }
    else
    {
        printf("%d",pour(a,b,c));
    }
    return 0;
}
