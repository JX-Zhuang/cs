#include <stdio.h>
#include <string.h>
void reverse(char s[]);
int main()
{
    char s[] = {'a', 'b', 'c', 'd', 'e'};
    reverse(s);
    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c ", s[i]);
    }
}
void reverse(char s[])
{
    int i = 0, j = strlen(s) - 1, temp;
    for (; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
