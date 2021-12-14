#include <stdio.h>
int main()
{
    int n, sum = 0, num;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &num);
            if (j == n)
                break;
            if ((i + j) == (n + 1))
                continue;
            sum += num;
        }
    }
    printf("%d\n", sum);
    return 0;
}
