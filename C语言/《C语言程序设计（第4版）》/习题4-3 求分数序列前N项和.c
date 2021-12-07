#include <stdio.h>
int main()
{
    int n;
    double sum = 0, a = 2, b = 1, temp;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        sum += a / b;
        temp = a;
        a = a + b;
        b = temp;
    }
    printf("%.2f", sum);
    return 0;
}