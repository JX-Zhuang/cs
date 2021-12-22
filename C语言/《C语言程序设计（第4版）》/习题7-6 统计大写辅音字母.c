#include <stdio.h>
int main()
{
    int n = 0;
    int c;
    while ((c = getchar()) != '\n')
    {
        if (c > 65 && c <= 90)
        {
            if (c != 69 && c != 73 && c != 79 && c != 85)
                n++;
        }
    }
    printf("%d", n);
    return 0;
}