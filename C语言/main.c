#include <stdio.h>
int main()
{
    double a, b, c;
    int d;
    b = 3.3;
    c = 1.1;
    a = b / c;
    d = b / c;
    printf("%f,%d\n", a, d);
    if (3.0 != a)
        printf("3.0!=a\n");
}