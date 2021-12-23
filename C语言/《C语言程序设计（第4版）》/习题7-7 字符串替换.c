#include <stdio.h>
int main()
{
    char arr[] = {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
    int c;
    while ((c = getchar()) != '\n')
    {
        if (c >= 65 && c <= 90)
        {
            putchar(arr[c - 65]);
        }
        else
        {
            putchar(c);
        }
    }
    return 0;
}