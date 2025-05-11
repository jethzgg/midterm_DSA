#include <stdio.h>
#include <string.h>

int main()
{
    char s1[100],s2[100],t[200],tnew[400];
    fgets(s1,100,stdin);
    s1[strlen(s1) - 1] = '\0';
    fgets(s2,100,stdin);
    s2[strlen(s2) - 1] = '\0';
    fgets(t,200,stdin);
    t[strlen(t) - 1] = '\0';
    int index_new = 0, index_check = 0, count = 0;
    for (int i = 0; i < strlen(t); i++)
    {
        if (t[i] == s1[index_check])
        {
            count++;
            index_check++;
        }
        else if (index_check >= strlen(s1))
        {
            if (count == strlen(s1))
            {
                for (int k = 0; k < strlen(s2); k++)
                {
                    tnew[index_new++] = s2[k];
                }
                tnew[index_new++] = ' '; 
                count = 0;
                index_check = 0;
            }
            else
            {
                i -= (index_check);
                count = 0;
                index_check = 0;
                tnew[index_new++] = t[i];
            }
        }
        else 
        {
            i -= (index_check);
            count = 0;
            index_check = 0;
            tnew[index_new++] = t[i];
        }
    }
    tnew[strlen(tnew) - 1] = '.';
    printf("%s",tnew);
}