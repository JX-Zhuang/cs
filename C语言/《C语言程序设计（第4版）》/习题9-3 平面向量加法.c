#include <stdio.h>
int main()
{
    double x1, y1, x2, y2;
    scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
    double v1 = x1 + x2, v2 = y1 + y2;
    if (v1 > -0.05 && v1 < 0)
        v1 = 0.0;
    if (v2 > -0.05 && v2 < 0)
        v2 = 0.0;
    printf("(%.1f, %.1f)", v1, v2);
    return 0;
}