#include <stdio.h>
int main()
{
    int c = 0;
    while ((c = getchar()) != '\n')
    {
        // scanf("%d",&c);
        if (c >= 65 && c < 90)
        {
            putchar(c + 33);
        }
        else if (c >= 97 && c < 122)
        {
            putchar(c - 31);
        }
        else if (c == 90)
        {
            printf("a");
        }
        else if (c == 122)
        {
            printf("A");
        }
        else
        {
            putchar(c);
        }
    }
    return 0;
}
