#include <stdio.h>
main1()
{
    int c, i, nwhite, nother;
    int ndigit[10];
    nwhite = nother = 0;
    for (i = 0; i < 10; ++i)
        ndigit[i] = 0;
    while ((c = getchar()) != EOF)
    {
        if (c > '0' && c <= '9')
            ++ndigit[c - '0'];
        else if (c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else
            ++nother;
    }
    printf("digits =");
    for (i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n", nwhite, nother);
}
main2()
{
    int c, len, i;
    len = i = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            int ndigit[len];
            for (i = 0; i < len; ++i)
                printf("-");
            printf("\n");
            for (i = 0; i < len; ++i)
            {
                if (i == len - 1)
                {
                    printf("|");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
            for (i = 0; i < len; ++i)
                printf("-");
            printf("\nlength = %d\n", len);
            len = 0;
        }
        else
        {
            len++;
        }
    }
}
// 练习1-13
#define MAXHIST 15
#define MAXWORD 11
#define IN 1
#define OUT 0
practice113()
{
    int c, i, nc, state;
    int len;
    int maxvalue;
    int ovflow;
    int wl[MAXWORD];
    
}