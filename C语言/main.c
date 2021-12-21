#include <stdio.h>
int main()
{
    int x = 5342;
    int *p = NULL;
    p = &x;
    printf("x:%d\n", x);
    printf("p:%p\n*p:%d\n", p, *p);
    return 0;
}
