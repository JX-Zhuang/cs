#include <stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int arr[n];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[n - i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            printf("%d", arr[i]);
        }
        else
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}