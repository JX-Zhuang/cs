#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void strcopy(char *s, char *t);
void printStr(char *s);
int main()
{
    char *str1 = "hello world!";
    char *str2 = (char *)malloc(strlen(str1) + 1);
    strcopy(str2, str1);
    printStr(str2);
    return 0;
}
void strcopy(char *s, char *t)
{
    while ((*s++ = *t++) != '\0')
        ;
}
void printStr(char *s)
{
    while (*s)
    {
        printf("%c", *s++);
    }
}