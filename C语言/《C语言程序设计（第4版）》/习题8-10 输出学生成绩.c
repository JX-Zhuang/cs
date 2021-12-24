#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, *a;
    scanf("%d", &n);
    a = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    double total = 0, max = 0, min = 1000;
    for (int i = 0; i < n; i++)
    {
        total += a[i];
        if (max < a[i])
            max = a[i];
        if (min > a[i])
            min = a[i];
    }
    free(a);
    printf("average = %.2f\n", total / n);
    printf("max = %.2f\n", max);
    printf("min = %.2f\n", min);
    return 0;
}