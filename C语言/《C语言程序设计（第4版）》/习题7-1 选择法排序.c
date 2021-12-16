#include <stdio.h>
int main()
{
    int n = 0, i = 0, maxIndex, temp;
    scanf("%d", &n);
    int arr[n];
    while (i != n)
    {
        scanf("%d", &arr[i]);
        i++;
    }
    for (int i = 0; i < n; i++)
    {
        maxIndex = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] > arr[maxIndex])
            {
                maxIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            printf("%d", arr[i]);
            continue;
        }
        printf("%d ", arr[i]);
    }
    return 0;
}