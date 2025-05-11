#include <stdio.h>

int a[9][9], rows[9][9], cols[9][9], sqrs[9][9];

int initCheck()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            rows[i][j] = 0;
            cols[i][j] = 0;
            sqrs[i][j] = 0;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (a[i][j] != 0)
            {
                if (rows[i][a[i][j] - 1]) return 0;
                rows[i][a[i][j] - 1]++;
                if (cols[j][a[i][j] - 1]) return 0;
                cols[j][a[i][j] - 1]++;
                if (sqrs[(j / 3) * 3 + (i / 3)][a[i][j] - 1]) return 0;
                sqrs[(j / 3) * 3 + (i / 3)][a[i][j] - 1]++;
            }
        }
    }
    return 1;
}

int check(int i, int j, int x)
{
    if (rows[i][x - 1]) return 0;
    if (cols[j][x - 1]) return 0;
    if (sqrs[(j / 3) * 3 + (i / 3)][x - 1]) return 0;
    return 1;
}

int backtrack(int a[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (!a[i][j])
            {
                int count = 0;
                for (int x = 1; x <= 9; x++)
                {
                    if (check(i,j,x))
                    {
                        a[i][j] = x;
                        rows[i][x - 1]++;
                        cols[j][x - 1]++;
                        sqrs[(j / 3) * 3 + (i / 3)][x - 1]++;
                        count += backtrack(a);
                        a[i][j] = 0;
                        rows[i][x - 1]--;
                        cols[j][x - 1]--;
                        sqrs[(j / 3) * 3 + (i / 3)][x - 1]--;
                    }
                }
                return count;
            }
        }
    }
    return 1;
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    initCheck();
    printf("%d\n",backtrack(a));
    return 0;
}

