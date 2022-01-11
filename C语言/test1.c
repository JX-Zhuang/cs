#include <stdio.h>
#include <string.h>
void strcopy(char *s, char *t);
int main()
{
    char *str1 = "hello world!";
    char *str2 = "";
    strcopy(str2, str1);
    printf("%c\n", *str1);
    printf("%c\n", *str2);
    return 0;
}
void strcopy(char *s, char *t)
{
    while ((*s = *t) != '\0')
    {
        s++;
        t++;
    }
}