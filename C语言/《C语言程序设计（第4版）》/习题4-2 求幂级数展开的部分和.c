#include <stdio.h>
int main()
{
    double x, sum = 1, prev = 1.0, n = 1.0;
    scanf("%lf", &x);
    while (prev >= 0.00001)
    {
        prev = prev * x / n;
        sum += prev;
        n++;
    }
    printf("%.4f", sum);
    return 0;
}
