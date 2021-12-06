#include <stdio.h>
int isPrime(int n)
{
    if (n == 1)
        return 0;
    int i = 2;
    while (i < n)
    {
        if (n % i == 0)
            return 0;
        i++;
    }
    return 1;
}
int main()
{
    int n, m, count = 0, sum = 0;
    scanf("%d%d", &m, &n);
    for (int i = m; i <= n; i++)
    {
        if (isPrime(i) == 1)
        {
            count++;
            sum += i;
        }
    }
    printf("%d %d", count, sum);
    return 0;
}
