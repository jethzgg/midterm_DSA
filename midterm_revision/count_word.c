#include <stdio.h>

int main()
{
    char s;
    int count = 0;
    scanf("%c",&s);
    while (s != '\0')
    {
        if (s == ' ' || s == '\n' || s == '\t')
        {
            count += 1;
        }
        scanf("%c",&s);
    }
    printf("%d\n",count);
    return 0;
}