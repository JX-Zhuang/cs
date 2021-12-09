#include <stdio.h>
int main()
{
    int h, n;
    scanf("%d%d", &h, &n);
    if (n == 0)
    {
        printf("0.0 0.0");
        return 0;
    }
    double l = h, m = h / 2.0;
    for (int i = 2; i <= n; i++)
    {
        l += m * 2;
        m /= 2.0;
    }
    printf("%.1f %.1f", l, m);
    return 0;
}
