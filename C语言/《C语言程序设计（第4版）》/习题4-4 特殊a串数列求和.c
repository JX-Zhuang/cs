#include <stdio.h>
int main()
{
    int sum = 0, a, n;
    scanf("%d%d", &a, &n);
    int current = a;
    for (int i = 1; i <= n; i++)
    {
        sum += current;
        current = current * 10 + a;
    }
    printf("s = %d", sum);
    return 0;
}
