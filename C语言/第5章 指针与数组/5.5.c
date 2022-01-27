#include <stdio.h>
#include <stdlib.h>
void strcpyArr(char *s, char *t)
{
    int i = 0;
    while ((s[i] = t[i]) != '\0')
    {
        i++;
    }
}
void strcpyP(char *s, char *t)
{
    while (*s++ = *t++)
        ;
}
int strcmpArr(char *s, char *t)
{
    int i = 0;
    for (; s[i] == t[i]; i++)
    {
        if (s[i] == '\0')
            return 0;
    }
    return s[i] - t[i];
}
int strcmpP(char *s, char *t)
{
    for (; *s == *t; s++, t++)
    {
        if (*s == '\0')
            return 0;
    }
    return *s - *t;
}
void strcatP(char *s, char *t)
{
    while (*s)
        s++;
    while (*s++ = *t++){
        printf("x\n");
    }
}
int main()
{
    char *s = (char *)malloc(100);
    char *t = "abc";
    char *t2 = "defg";
    strcatP(s, t);
    strcatP(s, t2);
    printf("s = %s\n", s);
    printf("t = %s\n", t);
    return 0;
}