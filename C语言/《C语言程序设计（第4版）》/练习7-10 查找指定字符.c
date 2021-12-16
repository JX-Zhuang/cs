#include <stdio.h>
#include <string.h>
int main()
{
    char c, b, str[81];
    scanf("%c\n", &c);
    gets(str);
    int index = 0, l = strlen(str), flag = 0;
    for (int i = 0; i < l; i++)
    {
        if (str[i] == c)
        {
            index = i;
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("Not Found");
    }
    else
    {
        printf("index = %d", index);
    }

    return 0;
}
