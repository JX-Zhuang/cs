#include <stdio.h>
int sum(int a, int b)
{
    return a + b;
}
int sub(int a, int b)
{
    return a - b;
}
int mult(int a, int b)
{
    return a * b;
}
int division(int a, int b)
{
    return a / b;
}
int cal(int a, int b, int (*exec)(int a, int b))
{
    return (*exec)(a, b);
}
int main()
{
    int a = 10, b = 5;
    printf("sum %d\n", cal(a, b, sum));
    printf("sub %d\n", cal(a, b, sub));
    printf("mult %d\n", cal(a, b, mult));
    printf("division %d\n", cal(a, b, division));
    return 0;
}