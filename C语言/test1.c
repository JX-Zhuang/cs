#include <stdio.h>
int *f(int *p)
{
    return p;
}
int main(int argc, char **argv)
{
    // int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int m = sizeof(arr) / sizeof(arr[0]),
    //     n = sizeof(arr[0]) / sizeof(arr[0][0]);
    // for (int i = 0; i < m; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         printf("arr[%d][%d] = %d,%p\n", i, j, arr[i][j], &arr[i][j]);
    //     }
    // }
    // float f = 1.0;
    // short c = *(short *)&f;
    // printf("%d\n", c);

    //5
    // int x[] = {1, 2, 3}, *p = x, y;
    // for (int i = 0; i < sizeof(x) / sizeof(x[0]); i++)
    // {
    //     printf("x[%d] = %d,%p\n", i, x[i], &x[i]);
    // }
    // printf("p = %p,*p = %d,&p = %p\n", p, *p, &p);
    // y = *p++;
    // printf("p = %p,*p = %d,&p = %p\n", p, *p, &p);
    // printf("%d\n", y);
    // printf("%d\n", *p);
    // for (int i = 0; i < sizeof(x) / sizeof(x[0]); i++)
    // {
    //     printf("x[%d] = %d,%p\n", i, x[i], &x[i]);
    // }

    //15
    // struct
    // {
    //     int k;
    //     char s[30];
    // } a[5] = {{1, "ABC"}, {2, "abc"}}, *p = a;
    // // printf("%c\n", *p->s);
    // printf("%c\n", *(p++)->s);

    // printf("%c\n", **argv);
    for (int i = 0; i < argc; i++)
    {
        // printf("%s\n", argv[i]);
    }
    while (**argv)
    {
        printf("%c\n", **argv++);
    }
    // printf("%s", *argv);
    return 0;
}