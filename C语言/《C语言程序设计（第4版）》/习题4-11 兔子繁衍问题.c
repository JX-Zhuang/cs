#include <stdio.h>
int main()
{
    int N;
    scanf("%d", &N);
    int a = 1, b = 1, temp, i = 2;
    if (N == 1)
    {
        i = 1;
    }
    else
    {
        while (a < N)
        {
            temp = a;
            a += b;
            b = temp;
            i++;
        }
    }
    printf("%d", i);
    return 0;
}
