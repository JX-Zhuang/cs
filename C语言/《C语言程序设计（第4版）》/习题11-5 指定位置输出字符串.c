#include <stdio.h>

#define MAXS 10

char *match(char *s, char ch1, char ch2);

int main()
{
    char str[MAXS], ch_start, ch_end, *p;

    scanf("%s\n", str);
    scanf("%c %c", &ch_start, &ch_end);
    p = match(str, ch_start, ch_end);
    printf("%s\n", p);

    return 0;
}

/* 你的代码将被嵌在这里 */
char *match(char *s, char ch1, char ch2)
{
    char *p = NULL;
    int length = strlen(s), i = 0;
    for (; i < length && (ch1 != s[i]); i++)
        ;
    p = &s[i];
    for (; i < length; i++)
    {
        printf("%c", s[i]);
        if (s[i] == ch2)
            break;
    }
    printf("\n");
    return p;
}