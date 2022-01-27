#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    while (*s++ = *t++)
    {
        printf("x\n");
    }
}
int strend(char *s, char *t)
{
    int lenS = strlen(s), lenT = strlen(t);
    if (lenS < lenT)
        return 0;
    s = s + lenS - lenT;
    while (*s++ == *t++ && *s != '\0')
        ;
    return *s == '\0' && *t == '\0' ? 1 : 0;
}
void *myStrncpy(char *s, char *t, int n)
{
    while (*t && n-- > 0)
        *s++ = *t++;
    while (n-- > 0)
        *s++ = '\0';
}
void *myStrncat(char *s, char *t, int n)
{
    while (*s)
        s++;
    myStrncpy(s, t, n);
}
int myStrncmp(char *s, char *t, int n)
{
    for (; *s == *t; s++, t++)
    {
        if (*s == '\0' || --n <= 0)
            return 0;
    }

    return *s - *t;
}
int main()
{
    char *s1 = "abcd", *t1 = "abcdefghijklmn";
    printf("%d\n", myStrncmp(s1, t1, 5));
    return 0;
}