#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m, n, num;
    scanf("%d%d", &m, &n);
    int *arr = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        arr[i] = 0;
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &num);
            arr[i] += num;
        }
    }
    for (int i = 0; i < m; i++)
    {
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}