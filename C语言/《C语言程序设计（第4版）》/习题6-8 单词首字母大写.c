#include <stdio.h>
int main()
{
    int inWord = 0, c = 0;
    while ((c = getchar()) != '\n')
    {
        if (c == ' ')
        {
            inWord = 0;
        }
        else
        {
            if (inWord == 0)
            {
                inWord = 1;
                if (c >= 97 && c <= 122)
                {
                    c -= 32;
                }
            }
        }
        putchar(c);
    }
    return 0;
}
