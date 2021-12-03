#include <stdio.h>
int main()
{
    int letter = 0, blank = 0, digit = 0, other = 0;
    int c;
    for (int i = 0; i < 10; i++)
    {
        c = getchar();
        if (c >= '0' && c <= '9')
        {
            digit++;
        }
        else if (c == ' ' || c == '\n')
        {
            blank++;
        }
        else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            letter++;
        }
        else
        {
            other++;
        }
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d", letter, blank, digit, other);
    return 0;
}