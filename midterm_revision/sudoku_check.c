#include <stdio.h>

int a[10][10];

int check()
{
    int rows[10][10];
    int cols[10][10];
    int sqrs[10][10];
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            rows[i][j] = 0;
            cols[i][j] = 0;
            sqrs[i][j] = 0;
        }
    }
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (a[i][j] < 1 || a[i][j] > 9)
            {
                return 0;
            }
            if (rows[i][a[i][j]] == 1)
            {
                return 0;
            }
            rows[i][a[i][j]]++;
            if (cols[j][a[i][j]] == 1)
            {
                return 0;
            }
            cols[j][a[i][j]]++;
            if (1 <= i && i <= 3)
            {
                if (1 <= j && j <= 3)
                {
                    if (sqrs[1][a[i][j]] == 1)
                    {
                        return 0;
                    }
                    sqrs[1][a[i][j]]++;
                }
                if (4 <= j && j <= 6)
                {
                    if (sqrs[4][a[i][j]] == 1)
                    {
                        return 0;
                    }
                    sqrs[4][a[i][j]]++;
                }
                if (7 <= j && j <= 9)
                {
                    if (sqrs[7][a[i][j]] == 1)
                    {
                        return 0;
                    }
                    sqrs[7][a[i][j]]++;
                }
            }
            if (4 <= i && i <= 6)
            {
                if (1 <= j && j <= 3)
                {
                    if (sqrs[2][a[i][j]] == 1)
                    {
                        return 0;
                    }
                    sqrs[2][a[i][j]]++;
                }
                if (4 <= j && j <= 6)
                {
                    if (sqrs[5][a[i][j]] == 1)
                    {
                        return 0;
                    }
                    sqrs[5][a[i][j]]++;
                }
                if (7 <= j && j <= 9)
                {
                    if (sqrs[8][a[i][j]] == 1)
                    {
                        return 0;
                    }
                    sqrs[8][a[i][j]]++;
                }
            }
            if (7 <= i && i <= 9)
            {
                if (1 <= j && j <= 3)
                {
                    if (sqrs[3][a[i][j]] == 1)
                    {
                        return 0;
                    }
                    sqrs[3][a[i][j]]++;
                }
                if (4 <= j && j <= 6)
                {
                    if (sqrs[6][a[i][j]] == 1)
                    {
                        return 0;
                    }
                    sqrs[6][a[i][j]]++;
                }
                if (7 <= j && j <= 9)
                {
                    if (sqrs[9][a[i][j]] == 1)
                    {
                        return 0;
                    }
                    sqrs[9][a[i][j]]++;
                }
            }
        }
    }
    return 1;
}

int main()
{
    int T; // Number of test cases
    // Read the number of test cases
    if (scanf("%d", &T) != 1) {
        return 1; // Error reading T
    }

    // Loop for each test case
    while (T--)
    {
        // Read the 9x9 matrix for the current test case
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                // Read each number into the global array 'a'
                if (scanf("%d", &a[i][j]) != 1) {
                    return 1; // Error reading matrix element
                }
            }
        }

        // Call the check function and print the result (1 for valid, 0 for invalid)
        printf("%d\n", check());
    }

    return 0; 
}