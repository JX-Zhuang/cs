#include <stdio.h>
int main()
{
    int n = 0, max = 24 * 3600;
    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);
    scanf("%d", &n);
    s += h * 3600 + m * 60 + n;
    if (s >= max)
    {
        s -= max;
    }
    h = s / 3600;
    m = (s - h * 3600) / 60;
    s = s - m * 60 - h * 3600;
    if (h < 10)
        printf("0%d", h);
    else
        printf("%d", h);
    printf(":");
    if (m < 10)
        printf("0%d", m);
    else
        printf("%d", m);
    printf(":");
    if (s < 10)
        printf("0%d", s);
    else
        printf("%d", s);
    return 0;
}