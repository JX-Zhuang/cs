#include <stdio.h>
int main()
{
    // int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
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
    int x[] = {1, 2, 3}, *p = x, y;
    for (int i = 0; i < sizeof(x) / sizeof(x[0]); i++)
    {
        printf("x[%d] = %d,%p\n", i, x[i], &x[i]);
    }
    printf("p = %p,*p = %d,&p = %p\n", p, *p, &p);
    y = *p++;
    printf("p = %p,*p = %d,&p = %p\n", p, *p, &p);
    printf("%d\n", y);
    printf("%d\n", *p);
    for (int i = 0; i < sizeof(x) / sizeof(x[0]); i++)
    {
        printf("x[%d] = %d,%p\n", i, x[i], &x[i]);
    }
    return 0;
}