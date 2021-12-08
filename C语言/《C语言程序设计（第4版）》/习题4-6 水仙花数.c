#include <stdio.h>
int p(int n, int m)
{
    int result = 1;
    for (int i = 1; i <= m; i++)
    {
        result *= n;
    }
    return result;
}
int check(int num, int n)
{
    int origin = num;
    int result = 0;
    while (num != 0)
    {
        result += p(num % 10, n);
        num /= 10;
    }
    if (origin == result)
        return 1;
    return 0;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = p(10, n - 1); i <= p(10, n) - 1; i++)
    {
        if (check(i, n) == 1)
        {
            printf("%d\n", i);
        }
    }
    return 0;
}
