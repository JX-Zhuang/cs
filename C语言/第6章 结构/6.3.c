#include <stdio.h>
int main()
{
    struct
    {
        int len;
        char *str;
    } * p;
    char str = 'A';
    p->len = 123;
    p->str = &str;
    printf("*p->str = %c\n", *p->str);
    printf("*(p->str) = %c\n", *(p->str));
    printf("*(*p).str = %c\n", *(*p).str);

    return 0;
}