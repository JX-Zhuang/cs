#include <stdio.h>
int reverse(int arr[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    return 0;
}
int main()
{
    int n, m;
    scanf("%d %d\n", &n, &m);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    reverse(arr, 0, n - 1);
    reverse(arr, 0, m % n - 1);
    reverse(arr, m % n, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}