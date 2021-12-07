#include <stdio.h>
int main()
{
    int f5 = 5, f2 = 2, t, k;
    int count = 0;
    scanf("%d", &t);
    for (int i = t / f5; i >= 1; i--)
    {
        for (int j = t / f2; j >= 1; j--)
        {
            k = t - f5 * i - f2 * j;
            if (k <= 0 || i <= 0 || j <= 0)
                continue;
            count++;
            printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n", i, j, k, i + j + k);
        }
    }
    printf("count = %d", count);
    return 0;
}
