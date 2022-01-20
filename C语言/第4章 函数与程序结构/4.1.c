#include <stdio.h>
int strrindex(char s[], char t[])
{
    int pos = -1, i, j, k;
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            pos = i;
    }
    return pos;
}
int main()
{
    printf("%d\n", strrindex("abcdefabc", "abc"));
    printf("%d\n", strrindex("abcdefabc", "abc1"));
}