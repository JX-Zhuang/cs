#include <stdio.h>
int mycmp(const char *s1, const char *s2)
{
    while (*s1 == *s2 && *s1 != '\0')
    {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}
int main()
{
    char s1[] = "abc";
    char s2[] = "abc";
    char *s3 = s1;
    printf("%d\n", mycmp(s1, s2));
    s3++;
    printf("%s\n",s3);
    printf("%c\n", *s3);
    return 0;
}
