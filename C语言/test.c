#include <stdio.h>
#include <string.h>
int main()
{
    int i = 0, j = 0, flag = 0, has = 0;
    char str1[10000], str2[10000], c;
    while ((c = getchar()) != '\n')
    {
        str1[i++] = c;
    }
    while ((c = getchar()) != '\n')
    {
        str2[j++] = c;
    }
    for (int k = 0; k < j && j - k >= i; k++)
    {
        flag = 1;
        for (int g = 0; g < i; g++)
        {
            if (str1[g] != str2[k + g])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            has = 1;
            printf("%d ", k);
        }
    }
    if (has == 0)
        printf("-1");
    return 0;
}