#include <stdio.h>
int main()
{
    int N, count = 1;
    scanf("%d", &N);
    for (int i = N - 1; i >= 1; i--)
    {
        count = 2 * (count + 1);
    }
    printf("%d", count);
    return 0;
}
