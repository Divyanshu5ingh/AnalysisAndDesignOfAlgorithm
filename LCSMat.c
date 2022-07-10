#include <stdio.h>
#include <string.h>
void main()
{
    printf("\t\tLongest Common Subsequence\n\n");
    int m, n, i, j, l = 0;
    char s1[15000];
    char s2[15000];
    char lcs[15000];
    printf("Enter first string: \n");
    gets(s1);
    printf("Enter second string: \n");
    gets(s2);
    printf("\n");
    m = strlen(s1) + 1;
    n = strlen(s2) + 1;
    int no[m][n];
    int pos[m][n];

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i == 0 | j == 0)
            {
                no[i][j] = 0;
                pos[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                no[i][j] = 1 + no[i - 1][j - 1];
                pos[i][j] = 3;
            }
            else
            {
                if (no[i - 1][j] >= no[i][j - 1])
                {
                    no[i][j] = no[i - 1][j];
                    pos[i][j] = 1;
                }
                else
                {
                    no[i][j] = no[i][j - 1];
                    pos[i][j] = 2;
                }
            }
        }
    }

    printf("LCS Table: \n");
    printf("\t0\t");
    for (i = 0; i < n; i++)
    {
        printf("%c\t", s2[i]);
    }
    printf("\n0");
    for (i = 0; i < m; i++)
    {
        printf("%c\t", s1[i - 1]);
        for (j = 0; j < n; j++)
        {
            printf("%d\t", no[i][j]);
        }
        printf("\n");
    }

    printf("\n\nPath Traversal : \n\t0\t");

    for (i = 0; i < n; i++)
    {
        printf("%c\t", s2[i]);
    }
    printf("\n0");
    for (i = 0; i < m; i++)
    {
        printf("%c\t", s1[i - 1]);
        for (j = 0; j < n; j++)
        {
            if (pos[i][j] == 0)
                printf("0\t");
            if (pos[i][j] == 1)
                printf("^\t");
            if (pos[i][j] == 2)
                printf("<\t");
            if (pos[i][j] == 3)
                printf("\\\t");
        }
        printf("\n");
    }

    i = m - 1;
    j = n - 1;
    while (pos[i][j] != 0)
    {
        if (pos[i][j] == 3)
        {
            lcs[i - 1] = s1[i - 1];
            i--;
            j--;
        }
        else if (pos[i][j] == 2)
            j--;
        else if (pos[i][j] == 1)
            i--;
    }

    lcs[1] = '\0';
    strrev(lcs);

    printf("\n\nLCS : ");
    puts(lcs);
    printf("Length : %d", strlen(lcs));
}